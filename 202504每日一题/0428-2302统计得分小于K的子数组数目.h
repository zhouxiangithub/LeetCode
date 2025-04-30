#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, score = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            score += nums[j];
            while (i <= j && score * (j - i + 1) >= k) {
                score -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};