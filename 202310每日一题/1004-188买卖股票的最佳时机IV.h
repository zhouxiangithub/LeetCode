#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        k = min(k, n / 2);
        
        vector<int> buy(k + 1);
        vector<int> sell(k + 1);
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for (int i = 1; i <= k; i++)
        {
            buy[i] = sell[i] = INT_MIN / 2;
        }
        
        for (int i = 1; i < n; i++)
        {
            buy[0] = max(buy[0], sell[0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                buy[j] = max(buy[j], sell[j] - prices[i]);
                sell[j] = max(sell[j], buy[j - 1] + prices[i]);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};