#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; left++) {
            while (same < k && right < n - 1) {
                right++;
                same += cnt[nums[right]];
                cnt[nums[right]]++;
            }
            if (same >= k) {
                ans += n - right; // [(n-1)-(right+1)+1]+1
            }
            cnt[nums[left]]--;
            same -= cnt[nums[left]];
        }
        return ans;
    }
};