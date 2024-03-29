#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cnt[nums[i] * nums[j]]++;
            }
        }
        for (auto& [k, v] : cnt)
        {
            ans += v * (v - 1) * 4; //C(2,n)*8=n*(n-1)/2*8=n*(n-1)*4
        }
        return ans;
    }
};