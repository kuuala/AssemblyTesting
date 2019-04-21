#include "sequencing.h"
#include "assembly.h"
#include "levenshtein.h"

int main(int argc, char *argv[]) {
    data input = data();
    vector<vector<int>> graph;
    vector<string> reads_vec;
    int graph_size = 0;
    if (argc == 2) {
        if (string(argv[1]) == "-h") {
            print_help();
        } else if (string(argv[1]) == "-ar") {
            auto_remove();
        }
    } else if (argc == 8) {
        parse_input(argc, argv, input);
        if (input.is_rand) {
            generate_sequence(input.sequence_length, input.source_dna);
        }
        reads_create(input, graph_size, reads_vec);
        fill_graph(input, graph_size, graph);
        save_graph(graph, input.graph_filename);
        system((input.tested_program + " -g " + input.graph_filename + " -r " + input.output_filename).c_str());
    } else {
        cout << "bad input" << endl;
        print_help();
    }
    //build_dna(input.output_filename, graph_size, reads_vec, graph);
    //cout << endl << "coincidence rate: " << editing_distance(input.source_dna, resultdna) << '%' << endl;
}