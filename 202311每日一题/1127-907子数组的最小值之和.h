#pragma once
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        stack<int> sk;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            while (!sk.empty() && arr[sk.top()] > arr[i])
            {
                sk.pop();
            }
            int k = sk.empty() ? (i + 1) : (i - sk.top());
            dp[i] = k * arr[i] + (sk.empty() ? 0 : dp[i - k]);
            ans = (ans + dp[i]) % mod;
            sk.emplace(i);
        }
        return ans;
    }
};