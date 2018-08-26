#ifndef ASSEMBLYTESTING_ASSEMBLY_HPP
#define ASSEMBLYTESTING_ASSEMBLY_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

void fill_graph(string &readsfile, const int graph_size, vector<vector<int>> &graph, const int max_read_size);
void build_dna(string &resultdna, const int &graph_size, const vector<string> &reads_vec, const vector<vector<int>> &graph);

#endif //ASSEMBLYTESTING_ASSEMBLY_HPP
