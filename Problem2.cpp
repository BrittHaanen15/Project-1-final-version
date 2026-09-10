#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include "utils.hpp"

int main()
{
   //Generate x values
    std::vector<double> x = make_a_range(0, 1, 0.01, false);

    //Preall u
    std::vector<double> u(x.size());

    //Calculate
    for (int i = 0; i < u.size(); i++)
    {
        u[i] = 1 - (1 - exp(-10))*x[i] - exp(-10*x[i]);
    }

    //Optional reality check
    // for (const auto& element : u) 
    //     {
    //         std::cout << element << " ";
    //     }
    //     std::cout << "\n";

    //Write out
    // Open the data file for writing
    std::ofstream outFile("Project1/OutputProblem2.txt");

    // Write both vectors side by side (assuming they are the same size)
    for (int i = 0; i < x.size(); ++i) {
        outFile << x[i] << " " << u[i] << "\n";
    }

    // Close the file
    outFile.close();

return 0;
}
