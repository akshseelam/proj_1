#include "StringUtils.h"
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    std::string new_str = str;
    if (start < 0 || start >= new_str.length() || end < start){
        return "";
    }
    int length = end - start; 

    return new_str.substr(start, length);
}

std::string Capitalize(const std::string &str) noexcept{
    if (str.empty()) {
        return str;
    }
    std::string new_str = str;

    for (char &c : new_str) {
        c = std::tolower(c);
    }
    if (!new_str.empty()) {
        new_str[0] = std::toupper(new_str[0]);
    }
    for (int i = 1; i < new_str.length(); i++){
        if(std::isspace(new_str[i-1])) {
            new_str[i] = std::toupper(new_str[i]);
        }
    }
    return new_str;
}

std::string Upper(const std::string &str) noexcept{
    std::string new_str = str;
    for (int i = 0; i < new_str.length(); i++){
        new_str[i] = std::toupper(new_str[i]);
    }
    return new_str;
}

std::string Lower(const std::string &str) noexcept{
    std::string new_str = str;
    for (int i = 0; i < new_str.length(); i++){
        new_str[i] = std::tolower(new_str[i]);
    }
    return new_str;
}

std::string LStrip(const std::string &str) noexcept{
    std::string new_str = str;
    int first_space = new_str.find_first_not_of(" \t\n");
    if (first_space == std::string::npos) {
        return ""; //add error here maybe
    }
    return new_str.substr(first_space);
}

std::string RStrip(const std::string &str) noexcept{
    std::string new_str = str;
    int last_space = new_str.find_last_not_of(" \t\n");
    if (last_space == std::string::npos) {
        return ""; //add error here maybe
    }
    return new_str.substr(0, last_space + 1);
}

std::string Strip(const std::string &str) noexcept{
    std::string new_str = str;
    new_str = RStrip(new_str); 
    new_str = LStrip(new_str);
    return new_str;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string new_str = str;

    int string_length = new_str.length();
    int spacing = width - string_length;
    int left_spacing = spacing / 2;
    int right_spacing = spacing - left_spacing;

    std::string centered_string = std::string(left_spacing, fill) + new_str + std::string(right_spacing, fill); 
    
    return centered_string;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    std::string new_str = str;

    int string_length = new_str.length();
    int spacing = width - string_length;

    int left_spacing = 0;
    int right_spacing = spacing;

    std::string left_string = std::string(left_spacing, fill) + new_str + std::string(left_spacing, fill);
    
    return left_string;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    std::string new_str = str;

    int string_length = new_str.length();
    int spacing = width - string_length;
    int left_spacing = spacing;
    int right_spacing = 0;

    std::string right_string = std::string(left_spacing, fill) + new_str + std::string(right_spacing, fill); 
    
    return right_string;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string new_str = str;
    std::string old_str = old;
    std::string rep_str = rep;

    std::size_t position = new_str.find(old_str);

    while (position != std::string::npos) {
        new_str.replace(position, old_str.length(), rep_str);
        position = new_str.find(old_str, position + rep_str.length());
    }
    return new_str;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector< std::string > split_string;  
    if (splt.empty()) {
        for (char c : str) {
            split_string.push_back(std::string(1, c));
        }
    } else {

    size_t start = 0;
    size_t end = str.find(splt);

    while (end != std::string::npos) {
        std::string substring = str.substr(start, end - start);
        split_string.push_back(substring);

        start = end + splt.length();
        end = str.find(splt, start);
    }
    split_string.push_back(str.substr(start));

    }
    return split_string;
}

std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept{
    std::string new_str = "";
    std::vector<std::string> new_vect = vect;

    for (int i = 0; i < new_vect.size(); i++) {
        new_str += new_vect[i];

        if (i < new_vect.size() - 1) {
            new_str += str;
        }
    }
    return new_str;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::stringstream result;

    for (char ch : str) {
        if (ch == '\t') {
            for (int i = 0; i < tabsize; ++i) {
                result << ' ';
            }
         } else {
            result << ch;
            }
        }

        return result.str();
    }


int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    int x = left.size();
    int y = right.size();

    std::vector<int> prev(x + 1, 0), curr(x + 1, 0);

    for (int j = 0; j <= x; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= y; i++) {
        curr[0] = i;

        for (int j = 1; j <= x; j++) {
            int cost = (left[j - 1] == right[i - 1]) ? 0 : 1;

            if (ignorecase) {
                cost = (std::tolower(left[j - 1]) == std::tolower(right[i - 1])) ? 0 : 1;
            }

            int yx = std::min(1 + prev[j], 1 + curr[j - 1]);
            curr[j] = std::min(yx, cost + prev[j - 1]);
        }

        prev = curr;
    }

    return prev[x];
}
}
;
