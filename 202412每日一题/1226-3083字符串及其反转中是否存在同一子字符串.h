#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool isSubstringPresent(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            string substr = s.substr(i, 2);
            reverse(substr.begin(), substr.end());
            if (s.find(substr) != string::npos) {
                return true;
            }
        }
        return false;
    }
};