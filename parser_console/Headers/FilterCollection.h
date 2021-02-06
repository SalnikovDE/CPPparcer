//
// Created by danil on 06.02.21.
//

#ifndef PARSER_FILTERCOLLECTION_H
#define PARSER_FILTERCOLLECTION_H

#include "Filter.h"

class FilterCollection {
public:
    FilterCollection();
    void add_filter(const std::string &expression);
    int load_filters(const std::string &filename);
    const Filter* get_max_filter();
    const Filter* get_next_filter();
    void reset();
private:
    std::multiset<Filter> filters;
    std::multiset<Filter>::reverse_iterator current_iterator;
};


#endif //PARSER_FILTERCOLLECTION_H
