#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

/*
    1.所有正数之和就是最大子序列和
    2.最大和无论是去掉正数还是加上负数都相当于是减掉正数
    3.可以将所有数都看作正数再用最大和去减
*/
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (int& num : nums)
        {
            if (num >= 0)
            {
                sum += num;
            }
            else
            {
                num = -num;
            }
        }
        sort(nums.begin(), nums.end());

        long long ret = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({ nums[0],0 });
        for (int j = 2; j <= k; j++)
        {
            auto [num, idx] = pq.top();
            pq.pop();
            ret = num;
            if (idx == n - 1)
            {
                continue;
            }
            pq.push({ num + nums[idx + 1],idx + 1 });
            pq.push({ num - nums[idx] + nums[idx + 1],idx + 1 });
        }
        return sum - ret;
    }
};