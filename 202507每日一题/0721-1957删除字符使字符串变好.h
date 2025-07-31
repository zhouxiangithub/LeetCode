#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s;
        }
        string res;
        for (char ch : s) {
            int n = res.length();
            if (n >= 2 && ch == res[n - 1] && ch == res[n - 2]) {
                continue;
            }
            res.push_back(ch);
        }
        return res;
    }
};