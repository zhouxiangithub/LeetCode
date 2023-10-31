#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> que(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int num = que.top();
            que.pop();
            ans += num;
            que.push((num + 2) / 3);
        }
        return ans;
    }
};