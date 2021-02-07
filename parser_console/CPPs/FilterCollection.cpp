//
// Created by danil on 06.02.21.
//

#include "../Headers/FilterCollection.h"

FilterCollection::FilterCollection() {
    current_iterator = filters.rend();
};

void FilterCollection::add_filter(const std::string &expression) {
    filters.emplace(expression);
    current_iterator = filters.rbegin();
}

int FilterCollection::load_filters(const std::string &filename) {
    std::ifstream fin(filename);
    std::string expression;
    if (!fin.is_open()) {
        return -1;
    }
    while (std::getline(fin, expression, '\n')) {
        add_filter(expression);
    }
    return 0;
}

// Returns pointer (to avoid copying) to the "strictest" filter.
const Filter *FilterCollection::get_max_filter() {
    return &(*filters.rbegin());
}

// Returns pointer to the next filter. Increments iterator.
// Returns nulptr when finishes;
const Filter *FilterCollection::get_next_filter() {
    if (current_iterator != filters.rend()) {
        return &(*current_iterator++);
    }
    return nullptr;
}

// Reset iterator to max filter.
void FilterCollection::reset() {
    current_iterator = filters.rbegin();
}
