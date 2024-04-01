#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int res = 0;
        int x = 1;
        int n = coins.size(), index = 0;
        while (x <= target)
        {
            if (index < n && coins[index] <= x)
            {
                x += coins[index];
                index++;
            }
            else
            {
                x <<= 1;
                res++;
            }
        }
        return res;
    }
};