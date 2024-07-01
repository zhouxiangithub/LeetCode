#pragma once
using namespace std;
#include <string>

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum++;
            }
            else {
                //每个白球左边有多少黑球就要交换多少次
                res += sum;
            }
        }
        return res;
    }
};