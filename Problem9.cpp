#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include "utils.hpp"

int main()
{   
    double stepsize = 0.01;

   //Generate x values
    std::vector<double> x = make_a_range(stepsize, 1, stepsize, false);

    //Generate a, b, c
    std::vector<int> a(x.size(), -1); 
    std::vector<int> b(x.size(), 2);
    std::vector<int> c(x.size(), -1);  

    //Calculate g
    std::vector<double> g(x.size());
    for (int i = 0; i < g.size(); i++)
    {
        g[i] = stepsize*stepsize*(100*exp(-10*x[i]));
    }

    //Initialise zero vectors that we fill on the go
    std::vector<double> b_tilde(x.size(), 0); 
    std::vector<double> g_tilde(x.size(), 0); 
    std::vector<double> v(x.size(), 0); 


    //Forward propagation
    b_tilde[0] = 2;
    g_tilde[0] = g[0];
    for (int i = 1; i < g.size(); i++)
    {
        //According to equations given in Lecture Notes at https://github.com/anderkve/FYS3150/blob/master/lecture_notes/2026/lecture_notes.pdf
        //See also citations in project references
        b_tilde[i] = 2 - (1/b_tilde[i-1]);
        g_tilde[i] = g[i] + (g_tilde[i-1]/b_tilde[i-1]);
    }

    //Backward substitution
    v[v.size()-1] = g_tilde[v.size()-1]/b_tilde[v.size()-1];
    for (int i = (v.size()-2); i >= 0; i--)
    {
        //According to equations given in Lecture Notes at https://github.com/anderkve/FYS3150/blob/master/lecture_notes/2026/lecture_notes.pdf
        //See also citations in project references
        v[i] = (g_tilde[i] + v[i+1])/b_tilde[i];
    }
    

    // //Optional reality check
    // for (const auto& element : x) 
    //     {
    //         std::cout << element << " ";
    //     }
    //     std::cout << "\n"; 
    

    //Write out
    // Open the data file for writing
    std::ofstream outFile("Project1/OutputProblem9_n100.txt");

    // Write both vectors side by side (assuming they are the same size)
    for (int i = 0; i < x.size(); ++i) {
        outFile << x[i] << " " << v[i] << "\n";
    }

    // Close the file
    outFile.close();

return 0;
}

