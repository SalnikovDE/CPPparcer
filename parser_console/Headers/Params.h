//
// Created by danil on 06.02.21.
//

#ifndef PARSER_PARAMS_H
#define PARSER_PARAMS_H

#include <string>
#include <fstream>

struct Params {
    int params_load(const std::string &filename);

    Params() = default;
    std::string filters_filename;
    std::string output_filename;
    std::string input_filename;
};


#endif //PARSER_PARAMS_H
