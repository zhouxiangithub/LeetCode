#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int curr = 0;
        while (curr < s.size()) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        if (res.back().length() < k) {
            res.back() += string(k - res.back().length(), fill);
        }
        return res;
    }
};