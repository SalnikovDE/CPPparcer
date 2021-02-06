#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include "Headers/FilterCollection.h"
#include "Headers/FileHandler.h"


int main(int argc, char const *argv[]) {
    Params params;
    if (params.params_load("config") != 0) {
        std::cout << "Config file error.";
        return -1;
    }

    FilterCollection filters;
    if (filters.load_filters(params.filters_filename) != 0) {
        std::cout << "Filters loading error.";
    };

    FileHandler(params, filters).filter_file();

    return 0;
}


