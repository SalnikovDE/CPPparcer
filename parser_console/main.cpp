#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include "Headers/FilterCollection.h"
#include "Headers/FileHandler.h"


int main(int argc, char const *argv[]) {
    Params params;
    int err = 0;
    if ((err = params.params_load("config")) != 0) {
        if (err == -1) {
          std::cout << "Cannot open config files" << std::endl;
        } else if (err == -2) {
          std::cout << "Wrong config format" << std::endl;
        }
        return -1;
    }

    FilterCollection filters;
    if (filters.load_filters(params.filters_filename) != 0) {
        std::cout << "Filters loading error.";
    };

    if ((err = FileHandler(params, filters).filter_file()) != 0) {
        if (err == -1) {
          std::cout << "Input file error" << std::endl;
        }
        if (err == -2) {
          std::cout << "Output file error" << std::endl;
        }
    }

    return 0;
}
