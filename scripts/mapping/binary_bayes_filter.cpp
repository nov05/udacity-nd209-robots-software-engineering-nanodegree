#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
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
vector<vector<double>> l(mapWidth / gridWidth, vector<double>(mapHeight / gridHeight, l0));

double inverseSensorModel(double x, double y, double theta, double xi, double yi, double sensorData[])
{
    // You will be coding this section in the upcoming concept!
    return 0.4;
}

void occupancyGridMapping(double Robotx, double Roboty, double Robottheta, double sensorData[])
{
    // 1 - TODO: Generate a grid (size 300x150) and then loop through all the cells
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

            if (sqrt(pow(xi - Robotx, 2) + pow(yi - Roboty, 2)) <= Zmax)
            {
                l[x][y] = l[x][y] + inverseSensorModel(Robotx, Roboty, Robottheta, xi, yi, sensorData) - l0;
            }
        }
    }
}

int main()
{
    double timeStamp;
    double measurementData[8];
    double robotX, robotY, robotTheta;

    FILE *posesFile = fopen("poses.txt", "r");
    FILE *measurementFile = fopen("measurement.txt", "r");

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

    // Displaying the map
    for (int x = 0; x < mapWidth / gridWidth; x++)
    {
        for (int y = 0; y < mapHeight / gridHeight; y++)
        {
            cout << l[x][y] << " ";
        }
    }

    return 0;
}
