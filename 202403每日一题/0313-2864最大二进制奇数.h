#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.length() - cnt, '0') + '1';
    }
};