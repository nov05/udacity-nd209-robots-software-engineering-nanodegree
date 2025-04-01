#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <sstream> // Required for std::istringstream
// #include "src/matplotlibcpp.h" // Graph Library
#include "../include/matplotlibcpp.h" // Python2.7 graph Library

using namespace std;
namespace plt = matplotlibcpp;

// Grid dimensions
double gridWidth = 100, gridHeight = 100;
// Map dimensions
double mapWidth = 30000, mapHeight = 15000;
vector<vector<double>> l(mapWidth / gridWidth, vector<double>(mapHeight / gridHeight));

void visualization()
{
    // Set backend explicitly (before using pyplot) for Windows, nov05
    // plt::backend("AkAgg");  // for plt::show();
    plt::backend("Agg"); // for plt::save();

    // Graph Format
    plt::title("Map");
    plt::xlim(0, (int)(mapWidth / gridWidth));
    plt::ylim(0, (int)(mapHeight / gridHeight));

    // Draw every grid of the map
    for (double x = 0; x < mapWidth / gridWidth; x++)
    {
        cout << "Remaining Rows = " << mapWidth / gridWidth - x << endl;
        for (double y = 0; y < mapHeight / gridHeight; y++)
        {
            if (l[x][y] == 0)
            {
                // Green unkown state
                plt::plot({x}, {y}, "g.");
            }
            else if (l[x][y] > 0)
            {
                // Black occupied state
                plt::plot({x}, {y}, "k.");
            }
            else
            {
                // Red free state
                plt::plot({x}, {y}, "r.");
            }
            //// Plot the bottom 5 rows
            // if (y == 5)
            // {
            //     cout << "Breaking the loop at y = " << y << std::endl;
            //     break; // Exit the loop when i equals 5
            // }
        }
    }

    // Save the image and close the plot
    /*
    In Windows, use absolute path, or heaven knows whether the map will be generated
    and where it will be saved. And it takes very long time!
    */
    plt::save("D:/tmp/map.png");
    plt::clf();
}

int main()
{
    // Read the map from a local file
    string filePath = "D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/binary_bayes_filter_02_result.txt";
    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        return -1;
    }

    // Read the line from the file
    string line;
    if (getline(file, line))
    {
        istringstream iss(line); // Convert line to stream
        double num;
        // Read and fill the matrix
        for (int i = 0; i < mapWidth / gridWidth; ++i)
        {
            for (int j = 0; j < mapHeight / gridHeight; ++j)
            {
                if (iss >> num)
                {
                    // Read a value from the line
                    l[i][j] = num;
                }
            }
        }
    }

    // Print out the matrix
    // for (int i = 0; i < l.size(); ++i)
    // {
    //     for (int j = 0; j < l[i].size(); ++j)
    //     {
    //         std::cout << l[i][j] << " ";
    //     }
    // }

    // Visualize the map at the final step
    cout << "Wait for the image to generate..." << endl;
    visualization();
    cout << "Done!" << endl;

    return 0;
}

// In a PowerShell terminal:
// conda activate robond_py27
// $env:PYTHONHOME="D:\Users\guido\miniconda3\envs\robond_py27"
// $env:PYTHONPATH="D:\Users\guido\miniconda3\envs\robond_py27\Lib"
//
// In VS Code, choose menu "View -> Open View... -> Run and Debug" (Ctrl+Shift+D)
// Select the self-defined profile in .vscode for this C++ script