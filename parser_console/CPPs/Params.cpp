//
// Created by danil on 06.02.21.
//

#include "../Headers/Params.h"

int Params::params_load(const std::string &filename) {
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        return -1;
    }
    if (fin >> filters_filename); else return -2;
    if (fin >> input_filename); else return -2;
    if (fin >> output_filename); else return -2;

    return 0;
}