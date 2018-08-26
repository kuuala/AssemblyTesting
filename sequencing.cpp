#include "sequencing.hpp"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void generate_str(int text_length, string &sourcedna){
    srand(time(NULL));
    sourcedna = "sourcerandom.txt";
    ofstream source(sourcedna);
    string pattern = "atgc";
    string result_string;
    for(int i = 0; i < text_length; ++i){
        result_string += pattern[rand()%4];
    }
    source << result_string;
    source.close();
}

void replicate(int n, string &sourcedna){
    ifstream source(sourcedna);
    ofstream repl;
    for(int i = 0; i < n; ++i){
        source.seekg(0, source.beg);
        repl.open(sourcedna + "_rep" + to_string(i) + ".txt");
        repl << source.rdbuf();
        repl.close();
    }
    source.close();
}

void reads_create(const int min_length, const int max_length, const string &sourcedna, const string &readsfile, int &graph_size, vector<string> &reads_vec){
    srand(time(NULL));
    ifstream source(sourcedna);
    ofstream reads(readsfile);
    string in;
    source >> in;
    int delta = max_length - min_length;
    int current_index = 0;
    int current_random = 0;
    int ind = 0;
    while(current_index < in.length()){
        current_random = min_length + rand()%delta;
        reads_vec.emplace_back(in.substr(current_index, min(current_random, (int)in.length() - current_index)));
        reads <<  reads_vec[ind] << endl;
        current_index += current_random - rand()%current_random;
        ++ind;
    }
    graph_size = ind;
    reads.close();
    source.close();
}