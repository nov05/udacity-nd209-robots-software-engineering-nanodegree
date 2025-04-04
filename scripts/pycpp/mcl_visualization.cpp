#include "../include/matplotlibcpp.h" // Python2.7 graph Library
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdexcept> // throw errors
#include <random>    // C++ 11 Random Numbers


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


namespace plt = matplotlibcpp;
using namespace std;


// Landmarks
double landmarks[8][2] = {
    {20.0, 20.0}, {20.0, 80.0}, {20.0, 50.0}, {50.0, 20.0}, 
    {50.0, 80.0}, {80.0, 80.0}, {80.0, 20.0}, {80.0, 50.0}
};

// Map size in meters
double world_size = 100.0;

// Random Generators
random_device rd;
mt19937 gen(rd());

// Global Functions
double mod(double first_term, double second_term);
double gen_real_random();

class Robot
{
public:
    Robot()
    {
        // Constructor
        x = gen_real_random() * world_size;      // robot's x coordinate
        y = gen_real_random() * world_size;      // robot's y coordinate
        orient = gen_real_random() * 2.0 * M_PI; // robot's orientation

        forward_noise = 0.0; // noise of the forward movement
        turn_noise = 0.0;    // noise of the turn
        sense_noise = 0.0;   // noise of the sensing
    }

    void set(double new_x, double new_y, double new_orient)
    {
        // Set robot new position and orientation
        if (new_x < 0 || new_x >= world_size)
            throw std::invalid_argument("X coordinate out of bound");
        if (new_y < 0 || new_y >= world_size)
            throw std::invalid_argument("Y coordinate out of bound");
        if (new_orient < 0 || new_orient >= 2 * M_PI)
            throw std::invalid_argument("Orientation must be in [0..2pi]");

        x = new_x;
        y = new_y;
        orient = new_orient;
    }

    void set_noise(double new_forward_noise, double new_turn_noise, double new_sense_noise)
    {
        // Simulate noise, often useful in particle filters
        forward_noise = new_forward_noise;
        turn_noise = new_turn_noise;
        sense_noise = new_sense_noise;
    }

    vector<double> sense()
    {
        // Measure the distances from the robot toward the landmarks
        vector<double> z(sizeof(landmarks) / sizeof(landmarks[0]));
        double dist;

        for (int i = 0; i < sizeof(landmarks) / sizeof(landmarks[0]); i++)
        {
            dist = sqrt(pow((x - landmarks[i][0]), 2) + pow((y - landmarks[i][1]), 2));
            dist += gen_gauss_random(0.0, sense_noise);
            z[i] = dist;
        }
        return z;
    }

    Robot move(double turn, double forward)
    {
        if (forward < 0)
            throw std::invalid_argument("Robot cannot move backward");

        // turn, and add randomness to the turning command
        orient = orient + turn + gen_gauss_random(0.0, turn_noise);
        orient = mod(orient, 2 * M_PI);

        // move, and add randomness to the motion command
        double dist = forward + gen_gauss_random(0.0, forward_noise);
        x = x + (cos(orient) * dist);
        y = y + (sin(orient) * dist);

        // cyclic truncate
        x = mod(x, world_size);
        y = mod(y, world_size);

        // set particle
        Robot res;
        res.set(x, y, orient);
        res.set_noise(forward_noise, turn_noise, sense_noise);

        return res;
    }

    string show_pose()
    {
        // Returns the robot current position and orientation in a string format
        return "[x=" + to_string(x) + " y=" + to_string(y) + " orient=" + to_string(orient) + "]";
    }

    string read_sensors()
    {
        // Returns all the distances from the robot toward the landmarks
        vector<double> z = sense();
        string readings = "[";
        for (int i = 0; i < z.size(); i++)
        {
            readings += to_string(z[i]) + " ";
        }
        readings[readings.size() - 1] = ']';

        return readings;
    }

    double measurement_prob(vector<double> measurement)
    {
        // Calculates how likely a measurement should be
        double prob = 1.0;
        double dist;

        for (int i = 0; i < sizeof(landmarks) / sizeof(landmarks[0]); i++)
        {
            dist = sqrt(pow((x - landmarks[i][0]), 2) + pow((y - landmarks[i][1]), 2));
            prob *= gaussian(dist, sense_noise, measurement[i]);
        }

        return prob;
    }

    double x, y, orient;                           // robot poses
    double forward_noise, turn_noise, sense_noise; // robot noises

private:
    double gen_gauss_random(double mean, double variance)
    {
        // Gaussian random
        normal_distribution<double> gauss_dist(mean, variance);
        return gauss_dist(gen);
    }

    double gaussian(double mu, double sigma, double x)
    {
        // Probability of x for 1-dim Gaussian with mean mu and var. sigma
        return exp(-(pow((mu - x), 2)) / (pow(sigma, 2)) / 2.0) / sqrt(2.0 * M_PI * (pow(sigma, 2)));
    }
};

// Functions
double gen_real_random()
{
    // Generate real random between 0 and 1
    uniform_real_distribution<double> real_dist(0.0, 1.0); // Real
    return real_dist(gen);
}

double mod(double first_term, double second_term)
{
    // Compute the modulus
    return first_term - (second_term)*floor(first_term / (second_term));
}

double evaluation(Robot r, Robot p[], int n)
{
    // Calculate the mean error of the system
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        // the second part is because of world's cyclicity
        double dx = mod((p[i].x - r.x + (world_size / 2.0)), world_size) - (world_size / 2.0);
        double dy = mod((p[i].y - r.y + (world_size / 2.0)), world_size) - (world_size / 2.0);
        double err = sqrt(pow(dx, 2) + pow(dy, 2));
        sum += err;
    }
    return sum / n;
}
double max(double arr[], int n)
{
    // Identify the max element in an array
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void visualization(int n, Robot robot, int step, Robot p[], Robot pr[])
{
    // Draw the robot, landmarks, particles and resampled particles on a graph
    // p[]: particles
    // pr[]: particles resampled

    // Set backend explicitly (before using pyplot) for Windows, nov05
    // plt::backend("AkAgg");  // for plt::show();
    plt::backend("Agg");       // for plt::save();

    // Graph Format with Python library matplotlib
    plt::title("MCL, step " + to_string(step));
    plt::xlim(0, 100);
    plt::ylim(0, 100);

    // Draw particles in green
    for (int i = 0; i < n; i++)
    {
        plt::plot({p[i].x}, {p[i].y}, "go");
    }

    // Draw resampled particles in yellow
    for (int i = 0; i < n; i++)
    {
        plt::plot({pr[i].x}, {pr[i].y}, "yo");
    }

    // Draw landmarks in red
    for (int i = 0; i < sizeof(landmarks) / sizeof(landmarks[0]); i++)
    {
        plt::plot({landmarks[i][0]}, {landmarks[i][1]}, "ro");
    }

    // Draw robot position in blue
    plt::plot({robot.x}, {robot.y}, "bo");

    // Save/Show the image and close the plot
    // plt::show();  // nov05
    plt::save("D:/tmp/step" + to_string(step) + ".png");  // nov05
    plt::clf();
}

int main()
{
    // Practice Interfacing with Robot Class
    Robot my_robot;
    my_robot.set_noise(5.0, 0.1, 5.0);
    my_robot.set(30.0, 50.0, M_PI / 2.0);
    my_robot.move(-M_PI / 2.0, 15.0);
    // cout << myrobot.read_sensors() << endl;
    my_robot.move(-M_PI / 2.0, 10.0);
    // cout << myrobot.read_sensors() << endl;

    // Create a set of particles
    int n = 1000;
    Robot p[n];
    // Simulate a robot motion for each of these particles
    Robot p2[n];

    for (int i = 0; i < n; i++)
    {
        p[i].set_noise(0.05, 0.05, 5.0);
        // cout << p[i].show_pose() << endl;
    }

    // Re-initialize myrobot object and Initialize a measurment vector
    my_robot = Robot();
    vector<double> z;

    // Iterating 50 times over the set of particles
    int localization_steps = 20;

    for (int t = 0; t < localization_steps; t++)
    {
        // Move the robot and sense the environment afterwards
        my_robot = my_robot.move(0.1, 5.0);
        z = my_robot.sense();

        for (int i = 0; i < n; i++)
        {
            p2[i] = p[i].move(0.1, 5.0);
            p[i] = p2[i];
        }

        // Generate particle weights depending on robot's measurement
        double w[n];
        for (int i = 0; i < n; i++)
        {
            w[i] = p[i].measurement_prob(z);
            // cout << w[i] << endl;
        }

        // ####   DON'T MODIFY ANYTHING ABOVE HERE! ENTER CODE BELOW ####

        // TODO: Resample the particles with a sample probability proportional
        //       to the importance weight
        int index = gen_real_random() * n;
        double beta = 0.0;
        double max_weight = max(w, n);

        for (int i = 0; i < n; i++)
        {
            beta += gen_real_random() * 2.0 * max_weight;
            while (beta > w[index])
            {
                beta -= w[index];
                index = mod((index + 1), n);
            }
            p2[i] = p[index];
        }

        // if (t == 0 || t == (localization_steps -1) / 2 || t == localization_steps - 1) 
        // {
        //     visualization(n, my_robot, t, p, p2);
        // } 
        visualization(n, my_robot, t, p, p2);

        for (int i = 0; i < n; i++)
        {
            p[i] = p2[i];
            // cout << p[i].show_pose() << endl;
        }

        // Evaluate the error by priting it in this form:
        // Step = <t>, Evaluation = <error_value>;
        cout << "Step = " << t << ", Evaluation = " << evaluation(my_robot, p, n) << endl;
        
    }

    return 0;
}

// In a PowerShell terminal:
// conda activate robond_py27
// $env:PYTHONHOME="D:\Users\guido\miniconda3\envs\robond_py27"
// $env:PYTHONPATH="D:\Users\guido\miniconda3\envs\robond_py27\Lib"
//
// In VS Code, choose menu "View -> Open View... -> Run and Debug" (Ctrl+Shift+D)
// Select the self-defined configuration in .vscode/launch.json for this C++ script
// In my case, "C/C++: g++.exe build active file with Python2.7"