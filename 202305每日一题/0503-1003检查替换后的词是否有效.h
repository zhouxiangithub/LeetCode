#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool isValid(string s) {
        string res;
        for (auto c : s)
        {
            res.push_back(c);
            if (res.size() >= 3 && res.substr(res.size() - 3, 3) == "abc")
            {
                res.erase(res.end() - 3, res.end());
            }
        }
        return res.empty();
    }
};