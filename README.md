# Project 1 final version
All code and output files for Project 1 of Computational Physics

Submission for Britt Haanen

# How to compile and run
The code for each problem is written in the .cpp file with the associated problem name. I have already compiled the code into .exe files for each problem. If you wish to recompile, simply use g++ ProblemX.cpp src/*.cpp -I include -o ProblemX.exe
Then run the file using ./ProblemX.exe

This may be useful for Problem 8c, where the output file for n=10e7 was too large to be pushed to Github. By compiling the code with the appropriate step size 10e-7 and running it, the output file could be regenerated locally.

# Looking at results
All codes have been configured to write their outputs in .txt files to the subfolder Project 1. Take this into account when running code.
For a visualisation of all results, which correspond to the figures given in the latex document, check out the Jupyter notebook PlottingProject1.ipynb which reads in the .txt files for the relevant problems to visualise the results as plots. 
