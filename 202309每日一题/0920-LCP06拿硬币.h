#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minCount(vector<int>& coins) {
        int sum = 0;
        for (int coin : coins)
        {
            sum += (coin + 1) / 2;
        }
        return sum;
    }
};