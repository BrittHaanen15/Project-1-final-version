# Project 1 final version
All code and output files for Project 1 of Computational Physics

Submission for Britt Haanen

# Folder structure
The main folder contains the .cpp and .exe files for the problems that required coding.

\include contains the header files with all the function declarations that I use in my codes.

\src contains the .cpp files with the associated function definitions.

\Project 1 contains all the output files from running the codes. It also contains all the png files of the plots that were created in the Jupyter notebook to visualise my results.

\AI logs includes my interaction with ChatGPT to debug my implementation of problem 7a. Turns out a tilde was the problem :) see also my opened git issue at https://github.uio.no/anderkve/FYS3150-forum/issues/100

# How to compile and run
The code for each problem is written in the .cpp file with the associated problem name. I have already compiled the code into .exe files for each problem. If you wish to recompile, simply use g++ ProblemX.cpp src/*.cpp -I include -o ProblemX.exe
Then run the file using ./ProblemX.exe

This may be useful for Problem 8c, where the output file for n=10e7 was too large to be pushed to Github. By compiling the code with the appropriate step size 10e-7 and running it, the output file could be regenerated locally.

# Looking at results
All codes have been configured to write their outputs in .txt files to the subfolder Project 1. Take this into account when running code.
For a visualisation of all results, which correspond to the figures given in the latex document, check out the Jupyter notebook PlottingProject1.ipynb which reads in the .txt files for the relevant problems to visualise the results as plots. 
