#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    std::string new_str = str;
    if (start < 0 || start >= new_str.length() || end < start){
        return "";
    }
    int length = end - start; //maybe use static_cast<size_t>

    return new_str.substr(start, length);
}

std::string Capitalize(const std::string &str) noexcept{
    if (str.empty()) {
        return str;
    }
    std::string new_str = str;
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
    new_str = RStrip(new_str); //change this function a little bit to add error messages
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

    std::string left_string = std::string(left_spacing, fill) + new_str + std::string(right_spacing, fill); 
    
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

    std::size_t position = new_str.find(old_str)

    if (position != std::string::npos){
        new_str.replace(position, old_str.length(), rep_str)
    }
    return new_str;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector< std::string > split_string;
    std::string new_splt = splt;
    std::string new_str = str;

    int start = 0;
    size_t end = str.find(new_splt);

    while (end != std::string::npos){
        std::string substring = new_str.substr(start, end - start);

        split_string.push_back(substring);

        start = end + new_splt.length();

        end = str.find(new_splt, start);
    }
    split_string.push_back(new_str.substr(start));

    return split_string;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string new_str = "";
    std::vector <std::string> new_vect = vect;

    for (int i = 0; i < new_vect.size(); i++) {
        new_str = new_str + vect[i];

        if(i < new_vect.size() - 1) {
            new_str = str + new_str;
        }
    }
    return new_str;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string new_str;

    for (int i =  0; i < str.size(); i++) {
        char c = str[i];
        if (c == '\t') {
            int spaces = tabsize - (i % tabsize);
            new_str.append(spaces, ' ');
            i = i + spaces - 1;
        } else {
            new_str.push_back(c);
        }
    }
    return new_str;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    int x = left.size();
    int m = right.size();

    std::vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int j = 0; j <= n; j++) {
        prev[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            if (ignorecase) {
                if (std::tolower(left[i - 1]) == std::tolower(right[j - 1])) {
                    curr[j] = prev[j - 1];
                } else {
                    int mn = std::min(1 + prev[j], 1 + curr[j - 1]);
                    curr[j] = std::min(mn, 1 + prev[j - 1]);
                }
            } else {
                if (left[i - 1] == right[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int mn = std::min(1 + prev[j], 1 + curr[j - 1]);
                    curr[j] = std::min(mn, 1 + prev[j - 1]);
                }
            }
        }
        prev = curr;
    }

    return prev[n];
}

}
;