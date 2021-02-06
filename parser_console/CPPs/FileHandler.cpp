//
// Created by danil on 06.02.21.
//

#include "../Headers/FileHandler.h"


FileHandler::FileHandler(const Params &params, const FilterCollection &_filters) :
    filters(_filters), input_stream(params.input_filename), output_stream(params.output_filename) {
}

int FileHandler::filter_file() {
    if (!input_stream.is_open()) {
        return -1;
    }
    if (!output_stream.is_open()) {
        return -2;
    }
    std::string line;
    while(std::getline(input_stream, line, '\n')) {
        filters.reset();
        bool flag = true;
        auto filter_ptr = filters.get_max_filter();
        while (filter_ptr != nullptr) {
            filter_ptr = filters.get_next_filter();
            if (filter_ptr == nullptr) {
                break;
            }
            if (!filter_ptr->check_string(line)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            output_stream << line << std::endl;
        }
    }

    return 0;
}


