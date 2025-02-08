#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int value = 0;
            for (int j = i; j < n; j++) {
                value |= nums[j];
                if (value >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    const static int NUM = 30;

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(NUM);
        auto calc = [](vector<int>& bits)->int {
            int ans = 0;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] > 0) {
                    ans |= 1 << i;
                }
            }
            return ans;
        };

        int res = INT_MAX;
        for (int left = 0, right = 0; right < n; right++) {
            for (int i = 0; i < NUM; i++) {
                bits[i] += (nums[right] >> i) & 1;
            }
            while (left <= right && calc(bits) >= k) {
                res = min(res, right - left + 1);
                for (int i = 0; i < NUM; i++) {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};