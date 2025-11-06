#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, preCnt = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
            }
            else {
                preCnt = cnt;
                cnt = 1;
            }
            res = max(res, min(preCnt, cnt));
            res = max(res, cnt / 2);
        }
        return res >= k;
    }
};