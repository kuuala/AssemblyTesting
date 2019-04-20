#ifndef ASSEMBLYTESTING_SEQUENCING_HPP
#define ASSEMBLYTESTING_SEQUENCING_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

void generate_sequence(int text_length, string &source_dna);
void replicate(int n, string &sourcedna);
void reads_create(const int min_length, const int max_length, const string &sourcedna, const string &readsfile, int &graph_size, vector<string> &reads_vec);

#endif //ASSEMBLYTESTING_SEQUENCING_HPP
