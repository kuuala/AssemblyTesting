#include <iostream>
#include <vector>
#include <string>
#include "sequencing.hpp"
#include "assembly.hpp"
#include "levenshtein.hpp"

using namespace std;

inline void input_function(string &sourcedna, int &min_reads_length, int &max_reads_length);

int main() {
    string sourcedna = "sourcerandom.txt";
    string readsfile = "reads.txt";
    string resultdna = "result.txt";
    vector<vector<int>> graph;
    vector<string> reads_vec;
    int graph_size = 0;
    int max_reads_length;
    int min_reads_length;
    input_function(sourcedna, min_reads_length, max_reads_length);
    cout << endl << "DNA created" << endl;
    reads_create(min_reads_length, max_reads_length, sourcedna, readsfile, graph_size, reads_vec);
    cout << "Reads created" << endl;
    fill_graph(readsfile, graph_size, graph, max_reads_length);
    cout << "Graph filled" << endl;
    build_dna(resultdna, graph_size, reads_vec, graph);
    cout << "DNA built" << endl;
    cout << endl << "coincidence rate: " << editing_distance(sourcedna, resultdna) << '%' << endl;
}

inline void input_function(string &sourcedna, int &min_reads_length, int &max_reads_length){
    cout << "Input block" << endl;
    cout << "0 - to create genome sequence random" << endl;
    cout << "1 - to use existing genome sequence" << endl;
    int rand_or_exist;
    cout << "Chose your variant: ";
    cin >> rand_or_exist;
    switch (rand_or_exist){
        case 0:
            int text_length;
            cout << "Text length: ";
            cin >> text_length;
            if (text_length <= 0) {
                throw invalid_argument("bad value of text length: " + to_string(text_length));
            }
            generate_str(text_length, sourcedna);
            break;
        case 1:
            cout << "File with DNA: ";
            cin >> sourcedna;
            break;
        default:
            throw invalid_argument("bad value: " + to_string(rand_or_exist));
            break;
    }
    cout << endl << "Allowed reads length" << endl;
    cout << "Min length: ";
    cin >> min_reads_length;
    cout << "Max length: ";
    cin >> max_reads_length;
}