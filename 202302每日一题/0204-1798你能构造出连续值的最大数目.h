#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    假设已经构造出[0,x],新增y后可构造出的区间为:[0,x]和[y,x+y]
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 1;
        sort(coins.begin(), coins.end());
        for (auto& i : coins)
        {
            if (i > res)
            {
                break;
            }
            res += i;
        }
        return res;
    }
};