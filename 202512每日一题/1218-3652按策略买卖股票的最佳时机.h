#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profitSum(n + 1);
        vector<long long> priceSum(n + 1);
        for (int i = 0; i < n; i++) {
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        long long res = profitSum[n];
        // i-k+1 ~ i ==> k¸ö ==> [0, i-k]  0:[i-k+1, i-k/2]  1:[i-k/2+1, i]  [i+1, n-1]
        for (int i = k - 1; i < n; i++) {
            res = max(res, profitSum[i - k + 1] + (priceSum[i + 1] - priceSum[i - k / 2 + 1]) + (profitSum[n] - profitSum[i + 1]));
        }
        return res;
    }
};