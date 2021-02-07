//
// Created by danil on 05.02.21.
//
#include <string>
#include <vector>
#include <set>
#include <fstream>

#ifndef PARSER_FILTER_H
#define PARSER_FILTER_H

bool sub_string_find(const std::string &sub_str, const std::string &str);

/*
  Class used to check and contain filters.
*/
class Filter{
public:
    Filter(const std::string &expression);
    ~Filter()= default;
    bool check_string(const std::string &sting_to_check) const;
private:
    enum FILTER_TYPE {IN, NOT_IN, EMPTY}; // Empty filter will be used in case of error;
    FILTER_TYPE type;
    std::string sub_string;
    bool case_sensetive;
    friend bool operator<(const Filter &a, const Filter &b);
    std::string str_to_lower(const std::string &str) const;
};




#endif //PARSER_FILTER_H
