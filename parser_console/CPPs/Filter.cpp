//
// Created by danil on 05.02.21.
//

#include <iostream>
#include "../Headers/Filter.h"

Filter::Filter(const std::string &expression) {
    if (expression[0] == '+') {
        type = IN;
        case_sensetive = false;
    } else if (expression[0] == '-') {
        type = NOT_IN;
        case_sensetive = false;
    } else if (expression[0] == '#') {
        type = IN;
        case_sensetive = true;
    } else if (expression[0] == '=') {
        type = NOT_IN;
        case_sensetive = true;
    } else {
        std::cout << "Error in expression " << expression;
        type = EMPTY;
        case_sensetive = false;
        return;
    }
    if(case_sensetive){
        sub_string = std::string(expression, 1);
    } else {
        sub_string = std::string(str_to_lower(expression), 1);
    }


}

/* Checks if string satisfy the filter condition */
bool Filter::check_string(const std::string &sting_to_check) const {
    std::string check;
    if (!case_sensetive) {
        check = str_to_lower(sting_to_check);
    } else {
        check = sting_to_check;
    }
    if (type == EMPTY) {
        return true;
    }
    auto pos = check.find(sub_string);
    if (type == NOT_IN) {
        return pos == std::string::npos;
    }
    return pos != std::string::npos;
}

/* Strictness is a relation of order on filters. The "strictest" filter should exclude the most string.
 * It won't work every time but it should decrease average time of work on large inputs.*/
bool operator<(const Filter &a, const Filter &b) {
    // Empty filter is not strict
    if (a.type == Filter::EMPTY) {
        return b.type != Filter::EMPTY;
    }

    if (a.type == Filter::NOT_IN) {
        if (b.type == Filter::IN) {
            return true;
        } else {
            return b.sub_string.size() < a.sub_string.size();
        }
    }

    if (a.type == Filter::IN) {
        if (b.type == Filter::NOT_IN) {
            return false;
        } else {
            return a.sub_string.size() < b.sub_string.size();
        }
    }
    return false;
}

// Needed to check not case sensetive filter.
std::string Filter::str_to_lower(const std::string &str) const {
    std::string ret;
    for (auto c : str) {
        if ('A' <= c && c <= 'Z') {
            c += ('a' - 'A');
        }
        ret += c;
    }
    return ret;
}
