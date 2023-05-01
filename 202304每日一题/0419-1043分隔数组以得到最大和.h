#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--)
            {
                d[i] = max(d[i], d[j] + maxValue * (i - j));
                if (j > 0)
                {
                    maxValue = max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
};