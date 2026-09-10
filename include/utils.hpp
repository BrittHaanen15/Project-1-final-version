//Make a vector according to start, stop, step
std::vector<double> make_a_range(double start, double stop, double step, bool verbose);

//Generalised matrix algorithm with signature (-1, 2, -1) for problem set 1
//In future: could be good to generalise further to accept different signatures and boundary values, for now it's okay
std::vector<double> General_Algorithm(double step);

//Special matrix algorithm with signature (-1, 2, -1) for problem set 1
std::vector<double> Special_Algorithm(double step);