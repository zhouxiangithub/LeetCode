#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int len = nums.size(), n = len / 3;
        
        vector<long long> left(n + 1);
        long long sum = 0;
        priority_queue<int> lq;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            lq.push(nums[i]);
        }
        left[0] = sum;
        for (int i = n; i < 2 * n; i++) {
            sum += nums[i];
            lq.push(nums[i]);
            sum -= lq.top();
            lq.pop();
            left[i - (n - 1)] = sum;
        }

        long long right = 0;
        priority_queue<int, vector<int>, greater<int>> rq;
        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            right += nums[i];
            rq.push(nums[i]);
        }

        long long res = left[n] - right;
        for (int i = 2 * n - 1; i >= n; i--) {
            right += nums[i];
            rq.push(nums[i]);
            right -= rq.top();
            rq.pop();
            res = min(res, left[i - n] - right);
        }
        return res;
    }
};