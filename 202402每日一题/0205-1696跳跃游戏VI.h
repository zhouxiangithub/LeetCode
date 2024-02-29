#pragma once
using namespace std;
#include <vector>
#include <deque>

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> dqueue;
        dqueue.push_back(0);
        for (int i = 1; i < n; i++)
        {
            while (!dqueue.empty() && dqueue.front() < i - k)
            {
                dqueue.pop_front();
            }
            dp[i] = dp[dqueue.front()] + nums[i];
            while (!dqueue.empty() && dp[dqueue.back()] <= dp[i])
            {
                dqueue.pop_back();
            }
            dqueue.push_back(i);
        }
        return dp[n - 1];
    }
};