#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool doesAliceWin(string s) {
        size_t pos = s.find_last_of("aeiou");
        return pos != std::string::npos;
    }
};