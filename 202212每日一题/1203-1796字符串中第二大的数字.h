#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (char c : s)
        {
            if (isdigit(c))
            {
                int num = c - '0';
                if (num > first)
                {
                    second = first;
                    first = num;
                }
                else if (num<first && num>second)
                {
                    second = num;
                }
            }
        }
        return second;
    }
};