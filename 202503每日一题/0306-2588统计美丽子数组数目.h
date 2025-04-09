#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int mask = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int num : nums) {
            mask ^= num;
            ans += cnt[mask];
            cnt[mask]++;
        }
        return ans;
    }
};