//
// Created by danil on 06.02.21.
//

#ifndef PARSER_FILEHANDLER_H
#define PARSER_FILEHANDLER_H

#include <iostream>
#include <string>
#include <fstream>
#include "FilterCollection.h"
#include "Params.h"
#include <unordered_set>


class FileHandler {
public:
    FileHandler(const Params &params, const FilterCollection &_filters);
    int filter_file();

private:
    std::ifstream input_stream;
    std::ofstream output_stream;
    FilterCollection filters;
};


#endif //PARSER_FILEHANDLER_H
