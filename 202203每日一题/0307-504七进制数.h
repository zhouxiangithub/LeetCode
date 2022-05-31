#pragma once
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
        {
            return "0";
        }
        bool mark = (num < 0);
        num = abs(num);
        string res = "";
        while (num)
        {
            res.push_back(num % 7 + '0');
            num /= 7;
        }
        if (mark)
        {
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};