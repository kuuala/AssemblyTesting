#ifndef ASSEMBLYTESTING_SIMULATED_ANNEALING_HPP
#define ASSEMBLYTESTING_SIMULATED_ANNEALING_HPP

#include <vector>

using namespace std;

vector<int> simulated_annealing(double initial_temperature, double end_temperature, const int graph_size, const vector<vector<int>> &graph);

#endif //ASSEMBLYTESTING_SIMULATED_ANNEALING_HPP
