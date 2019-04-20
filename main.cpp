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
    reads_create(input, graph_size, reads_vec);
    fill_graph(input, graph_size, graph);
    /*
    build_dna(resultdna, graph_size, reads_vec, graph);
    cout << "DNA built" << endl;
    cout << endl << "coincidence rate: " << editing_distance(sourcedna, resultdna) << '%' << endl;
    */
}