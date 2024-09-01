#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        while (nums[0] > 0) {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                cnt[nums[i] % 10]++;
                nums[i] /= 10;
            }
            for (int j = 0; j < 10; j++) {
                res += (long long)cnt[j] * (n - cnt[j]);
            }
        }
        return res / 2;
    }
};