#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include "utils.hpp"


int main()
{

    std::vector<double> stepsizes = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001};
    
    //Initialise array for writing out the times
    std::vector<std::vector<double>> general_runtimes(11, std::vector<double>(stepsizes.size(), 0));

    //Assign to first row as header
    general_runtimes[0] = stepsizes;

    for (int i = 0; i < stepsizes.size(); i++)
    {
        
        for (int j = 1; j < 11; j++)
        {
            // Start measuring time
            // As given in Project 1 description at https://anderkve.github.io/FYS3150/book/projects/project1.html#equation-exact-solution
            auto t1 = std::chrono::high_resolution_clock::now();

            // Run general algo
            General_Algorithm(stepsizes[i]);

            // Stop measuring time
            auto t2 = std::chrono::high_resolution_clock::now();

            // Calculate the elapsed time
            // We use chrono::duration<double>::count(), which by default returns duration in seconds
            general_runtimes[j][i] = std::chrono::duration<double>(t2 - t1).count();

        }
    }


    //Write runtimes out as file
    // Open the data file for writing
    std::ofstream outFile("Project1/OutputProblem10_general.txt");

    for (const auto& row : general_runtimes) {
        for (size_t i = 0; i < row.size(); ++i) {
            outFile << row[i];
            if (i < row.size() - 1) {
                outFile << " "; 
            }
        }
        outFile << "\n"; 
    }
    outFile.close();

    //Repeat steps for the special algo/////////////////////////////////////////////////////////
    //Initialise array for writing out the times
    std::vector<std::vector<double>> special_runtimes(11, std::vector<double>(stepsizes.size(), 0));

    //Assign to first row as header
    special_runtimes[0] = stepsizes;

    for (int i = 0; i < stepsizes.size(); i++)
    {
        
        for (int j = 1; j < 11; j++)
        {
            // Start measuring time
            // As given in Project 1 description at https://anderkve.github.io/FYS3150/book/projects/project1.html#equation-exact-solution
            auto t1 = std::chrono::high_resolution_clock::now();

            // Run speciall algo
            Special_Algorithm(stepsizes[i]);

            // Stop measuring time
            auto t2 = std::chrono::high_resolution_clock::now();

            // Calculate the elapsed time
            // We use chrono::duration<double>::count(), which by default returns duration in seconds
            special_runtimes[j][i] = std::chrono::duration<double>(t2 - t1).count();

        }
    }


    //Write runtimes out as file
    // Open the data file for writing
    std::ofstream outFile2("Project1/OutputProblem10_special.txt");

    for (const auto& row : special_runtimes) {
        for (size_t i = 0; i < row.size(); ++i) {
            outFile2 << row[i];
            if (i < row.size() - 1) {
                outFile2 << " "; // Add space between numbers
            }
        }
        outFile2 << "\n"; // Newline at the end of each row
    }
    outFile2.close();

    return 0;
}


