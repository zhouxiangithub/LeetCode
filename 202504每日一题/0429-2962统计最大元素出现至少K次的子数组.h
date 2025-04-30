#pragma once
using namespace std;
#include <vector>
#include <algorithm>

// ����Ϊ׼
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> pos{ -1 };
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                pos.push_back(i);
            }
        }
        int left = 1, right = k;
        long long ans = 0;
        while (right < pos.size()) {
            ans += (pos[left] - pos[left - 1]) * (n - pos[right]);
            left++;
            right++;
        }
        return ans;
    }
};

// ����Ϊ׼
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int cnt = 0, left = 0;
        for (int num : nums) {
            if (num == mx) {
                cnt++;
            }
            while (cnt == k) {
                if (nums[left] == mx) {
                    cnt--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};