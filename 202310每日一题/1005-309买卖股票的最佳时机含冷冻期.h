#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        //f[i]表示第i天结束之后的累计最大收益
        int f0 = -prices[0]; //持有股票
        int f1 = 0; //没有股票,冷冻期
        int f2 = 0; //没有股票,非冷冻期
        for (int i = 1; i < n; i++)
        {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f2, f1);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1, f2);
    }
};