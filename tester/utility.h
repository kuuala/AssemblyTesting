#ifndef ASSEMBLYTESTING_UTILITY_H
#define ASSEMBLYTESTING_UTILITY_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

struct data {
    string source_dna;
    string tested_program;
    string reads_filename;
    string graph_filename;
    string output_filename;
    string result_filename;
    int min_reads_length = 0;
    int max_reads_length = 0;
    int sequence_length = 0;
    bool is_rand = false;
};

void print_help();

void parse_input(int argc, char *argv[], data &input);

void save_graph(vector<vector<int>> &graph, const string &filename);

void auto_remove();

#endif //ASSEMBLYTESTING_UTILITY_H
