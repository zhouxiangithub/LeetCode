#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = INT_MAX, max_val = 0;
        for (int price : prices)
        {
            max_val = max(max_val, price - min_val);
            min_val = min(min_val, price);
        }
        return max_val;
    }
};