#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len = colors.length();
        int res = 0;
        int i = 0;
        while (i < len) {
            char ch = colors[i];
            int sumTime = 0, maxTime = 0;
            while (i < len && colors[i] == ch) {
                maxTime = max(maxTime, neededTime[i]);
                sumTime += neededTime[i];
                i++;
            }
            res += sumTime - maxTime;
        }
        return res;
    }
};