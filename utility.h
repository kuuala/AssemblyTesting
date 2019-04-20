#ifndef ASSEMBLYTESTING_UTILITY_H
#define ASSEMBLYTESTING_UTILITY_H

#include <string>
#include <iostream>

using namespace std;

struct data {
    string source_dna, tested_program, reads_filename;
    int min_reads_length = 0;
    int max_reads_length = 0;
    int sequence_length = 0;
    bool is_rand = false;
};

void print_help();

void parse_input(int argc, char *argv[], data &input);

#endif //ASSEMBLYTESTING_UTILITY_H
