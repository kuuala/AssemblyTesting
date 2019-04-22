#include "sequencing.h"
#include "assembly.h"

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
    } else if (argc == 10) {
        parse_input(argc, argv, input);
        if (input.is_rand) {
            generate_sequence(input.sequence_length, input.source_dna);
        }
        reads_create(input, graph_size, reads_vec);
        fill_graph(input, graph_size, graph);
        save_graph(graph_size, graph, input.graph_filename);
        system((input.tested_program + " -g " + input.graph_filename + " -o " + input.output_filename).c_str());
        build_dna(input.output_filename, input.result_dna, graph_size, reads_vec, graph);
        system((input.meter_program + " " + input.source_dna + " " + input.result_dna).c_str());
    } else {
        cout << "bad input in tester" << endl;
        print_help();
    }
}
