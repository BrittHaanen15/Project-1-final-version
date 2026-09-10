#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include "utils.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Make a vector according to start, stop, step
std::vector<double> make_a_range(double start, double stop, double step, bool verbose)
{
    //Calc number of steps based on start, stop and step size
    int stepsnumber = static_cast<int>((stop-start)/step);

    //Preall vector of this size
    std::vector<double> output(stepsnumber);

    for (int i = 0; i < stepsnumber; i++)
    {
        output[i] = start + i*step;
    }

    //Reality check: print generated vector if needed
    if (verbose == true)
    {
        for (const auto& element : output) 
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
    
   return output;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Generalised matrix algorithm with signature (-1, 2, -1) for problem set 1
//In future: could be good to generalise further to accept different signatures and boundary values, for now it's okay
std::vector<double> General_Algorithm(double step)
{
    //Generate x values
    std::vector<double> x = make_a_range(step, 1, step, false);

    //Generate a, b, c
    std::vector<int> a(x.size(), -1); 
    std::vector<int> b(x.size(), 2);
    std::vector<int> c(x.size(), -1);  

    //Calculate g
    std::vector<double> g(x.size());
    for (int i = 0; i < g.size(); i++)
    {
        g[i] = step*step*(100*exp(-10*x[i]));
    }

    //Initialise zero vectors that we fill on the go
    std::vector<double> b_tilde(x.size(), 0); 
    std::vector<double> g_tilde(x.size(), 0); 
    std::vector<double> v(x.size(), 0); 


    //Forward propagation
    b_tilde[0] = b[0];
    g_tilde[0] = g[0];
    for (int i = 1; i < g.size(); i++)
    {
        //According to equations given in Lecture Notes at https://github.com/anderkve/FYS3150/blob/master/lecture_notes/2026/lecture_notes.pdf
        //See also citations in project references
        b_tilde[i] = b[i] - (a[i]/b_tilde[i-1])*c[i-1];
        g_tilde[i] = g[i] - (a[i]/b_tilde[i-1])*g_tilde[i-1];
    }

    //Backward substitution
    v[v.size()-1] = g_tilde[v.size()-1]/b_tilde[v.size()-1];
    for (int i = (v.size()-2); i >= 0; i--)
    {
        //According to equations given in Lecture Notes at https://github.com/anderkve/FYS3150/blob/master/lecture_notes/2026/lecture_notes.pdf
        //See also citations in project references
        v[i] = (g_tilde[i] - c[i]*v[i+1])/b_tilde[i];
    }
    
    return v;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Special matrix algorithm with signature (-1, 2, -1) for problem set 1
std::vector<double> Special_Algorithm(double step)
{   
   //Generate x values
    std::vector<double> x = make_a_range(step, 1, step, false);

    //Generate a, b, c
    std::vector<int> a(x.size(), -1); 
    std::vector<int> b(x.size(), 2);
    std::vector<int> c(x.size(), -1);  

    //Calculate g
    std::vector<double> g(x.size());
    for (int i = 0; i < g.size(); i++)
    {
        g[i] = step*step*(100*exp(-10*x[i]));
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

return v;
}



