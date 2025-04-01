#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

// Sensor characteristic: Min and Max ranges of the beams
double Zmax = 5000, Zmin = 170;
// Defining free cells(lfree), occupied cells(locc), unknown cells(l0) log odds values
// For p0 = 0.5, l0 = log(0.5/(1-0.5)) = log(1) = 0
double l0 = 0, locc = 0.4, lfree = -0.4;
// Grid dimensions
double gridWidth = 100, gridHeight = 100;
// Map dimensions
double mapWidth = 30000, mapHeight = 15000;
// Robot size with respect to the map
double robotXOffset = mapWidth / 5, robotYOffset = mapHeight / 3;
// Defining an l vector to store the log odds values of each cell, initialize with l0
vector<vector<double>> l(mapWidth / gridWidth, vector<double>(mapHeight / gridHeight));

double inverseSensorModel(double x, double y, double theta, double xi, double yi, double sensorData[])
{
    //******************Code the Inverse Sensor Model Algorithm**********************//
    // Defining Sensor Characteristics
    double Zk, thetaK, sensorTheta;
    double minDelta = -1;
    double alpha = 200, beta = 20;

    //******************TODO: Compute r and phi**********************//

    // Scaling Measurement to [-90 -37.5 -22.5 -7.5 7.5 22.5 37.5 90]
    for (int i = 0; i < 8; i++)
    {
        if (i == 0)
        {
            sensorTheta = -90 * (M_PI / 180);
        }
        else if (i == 1)
        {
            sensorTheta = -37.5 * (M_PI / 180);
        }
        else if (i == 6)
        {
            sensorTheta = 37.5 * (M_PI / 180);
        }
        else if (i == 7)
        {
            sensorTheta = 90 * (M_PI / 180);
        }
        else
        {
            sensorTheta = (-37.5 + (i - 1) * 15) * (M_PI / 180);
        }

        if (fabs(phi - sensorTheta) < minDelta || minDelta == -1)
        {
            Zk = sensorData[i];
            thetaK = sensorTheta;
            minDelta = fabs(phi - sensorTheta);
        }
    }

    //******************TODO: Evaluate the three cases**********************//
    // You also have to consider the cells with Zk > Zmax or Zk < Zmin as unkown states
}

void occupancyGridMapping(double robotX, double robotY, double robotTheta, double sensorData[])
{
    // 1 - TODO: Generate a grid (size 300x150 = 45000) and then loop through all the cells
    // 2- TODO: Compute the center of mass of each cell xi and yi
    // double xi = x * gridWidth + gridWidth / 2 - robotXOffset;
    // double yi = -(y * gridHeight + gridHeight / 2) + robotYOffset;
    // 3- TODO: Check if each cell falls under the perceptual field of the measurements
    for (int x = 0; x < mapWidth / gridWidth; x++)
    {
        for (int y = 0; y < mapHeight / gridHeight; y++)
        {
            double xi = x * gridWidth + gridWidth / 2 - robotXOffset;
            double yi = -(y * gridHeight + gridHeight / 2) + robotYOffset;

            if (sqrt(pow(xi - robotX, 2) + pow(yi - robotY, 2)) <= Zmax)
            {
                l[x][y] = l[x][y] + inverseSensorModel(robotX, robotY, robotTheta, xi, yi, sensorData) - l0;
            }
        }
    }
}

bool compare2DTo1D(const std::vector<double> &v1, const std::vector<std::vector<double>> &v2)
{
    size_t rows = v2.size();
    size_t cols = v2[0].size();

    // Check if the total number of elements in 2D vector matches 1D vector
    if (rows * cols != v1.size())
    {
        return false;
    }

    // Perform element-wise comparison
    size_t index = 0;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            // round to 1 decimal and compare
            if (std::round(v2[i][j] * 10.0) / 10.0 != std::round(v1[index] * 10.0) / 10.0)
            {
                return false; // Mismatch found
            }
            ++index;
        }
    }

    return true; // All elements match
}

void verify(const std::string &filePath, const std::vector<std::vector<double>> &v2)
{
    bool verify_result;
    std::vector<double> v1;
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }
    double num;
    while (file >> num) // Read double numbers directly from the file
    {
        v1.push_back(num);
    }
    file.close();

    verify_result = compare2DTo1D(v1, v2);
    std::cout << "Verify result: " << (verify_result ? "true" : "false") << std::endl;
}

int main()
{
    double timeStamp;
    double measurementData[8];
    double robotX, robotY, robotTheta;
    std::string resultFile;

    // FILE *posesFile = fopen("posese.txt", "r");
    // FILE *measurementFile = fopen("measurement.txt", "r");
    FILE *posesFile = fopen("D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/posese.txt", "r");
    FILE *measurementFile = fopen("D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/measurement.txt", "r");

    // Scanning the files and retrieving measurement and poses at each timestamp
    while (fscanf(posesFile, "%lf %lf %lf %lf", &timeStamp, &robotX, &robotY, &robotTheta) != EOF)
    {
        // Read the time stamp of a line
        fscanf(measurementFile, "%lf", &timeStamp);
        for (int i = 0; i < 8; i++)
        {
            // Read the 8 measurements of a line
            fscanf(measurementFile, "%lf", &measurementData[i]);
        }
        occupancyGridMapping(robotX, robotY, (robotTheta / 10) * (M_PI / 180), measurementData);
    }

    // Display the map
    // for (int x = 0; x < mapWidth / gridWidth; x++)
    // {
    //     for (int y = 0; y < mapHeight / gridHeight; y++)
    //     {
    //         cout << l[x][y] << " ";
    //     }
    // }

    // Verify the map
    // resultFile = "binary_bayes_filter_02_result.txt";
    resultFile = "D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/binary_bayes_filter_02_result.txt";
    verify(resultFile, l);

    return 0;
}

// Expected output:
// Verify result: true
