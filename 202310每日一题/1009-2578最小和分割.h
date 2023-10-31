#pragma once
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
    int splitNum(int num) {
        string strnum = to_string(num);
        sort(strnum.begin(), strnum.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < strnum.size(); i++)
        {
            if (i % 2 == 0)
            {
                num1 = num1 * 10 + (strnum[i] - '0');
            }
            else
            {
                num2 = num2 * 10 + (strnum[i] - '0');
            }
        }
        return num1 + num2;
    }
};
