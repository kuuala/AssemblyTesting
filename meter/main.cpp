#include "levenshtein.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    if (argc == 3) {
        cout << "rate: " << editing_distance(string(argv[1]), string(argv[2])) << '%' << endl;
    } else {
        cout << "bad input in meter" << endl;
    }
}
