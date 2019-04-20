#include <iostream>
#include <string>
#include "sequencing.hpp"
#include "assembly.hpp"
#include "levenshtein.hpp"

using namespace std;

struct data {
    string source_dna, tested_program;
    int min_reads_length = 0;
    int max_reads_length = 0;
    int sequence_length = 0;
    bool is_rand = false;
};

void print_help();
void parse_input(int argc, char *argv[], data &input);

int main(int argc, char *argv[]) {
    data input;
    //vector<vector<int>> graph;
    //vector<string> reads_vec;
    //int graph_size = 0;
    if (argc == 2) {
        if (string(argv[1]) == "-h") {
            print_help();
        }
    } else if (argc == 8) {
        parse_input(argc, argv, input);
        if (input.is_rand) {
            generate_sequence(input.sequence_length, input.source_dna);
        }
    } else {
        cout << "bad input" << endl;
        print_help();
    }


    reads_create(min_reads_length, max_reads_length, sourcedna, readsfile, graph_size, reads_vec);
    cout << "Reads created" << endl;
    /*
    fill_graph(readsfile, graph_size, graph, max_reads_length);
    cout << "Graph filled" << endl;
    build_dna(resultdna, graph_size, reads_vec, graph);
    cout << "DNA built" << endl;
    cout << endl << "coincidence rate: " << editing_distance(sourcedna, resultdna) << '%' << endl;
    */
}

void print_help() {
    cout << "-h - help about tool" << endl;
    cout << "-r [length] - generate random sequence" << endl;
    cout << "-e [filename] - use existing sequence" << endl;
    cout << "-rl [min][max] - min and max reads length" << endl;
    cout << "-t [exe name] - name of tested program" << endl;
}

void parse_input(int argc, char *argv[], data &input) {
    int current = 1;
    while (current < argc) {
        if (string(argv[current]) == "-r") {
            input.is_rand = true;
            input.source_dna = "source.txt";
            ++current;
            input.sequence_length = atoi(argv[current]);
        } else if (string(argv[current]) == "-e") {
            input.is_rand = false;
            ++current;
            input.source_dna = string(argv[current]);
        } else if (string(argv[current]) == "-rl") {
            ++current;
            input.min_reads_length = atoi(argv[current]);
            ++current;
            input.max_reads_length = atoi(argv[current]);
            if (input.max_reads_length < input.min_reads_length ||
                input.min_reads_length < 1 ||
                input.max_reads_length < 1) {
                cout << "-rl bad values" << endl;
                exit(0);
            }
        } else if (string(argv[current]) == "-t") {
            ++current;
            input.tested_program = string(argv[current]);
        }
        ++current;
    }
}