#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int begin = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (begin <= end && nums[end] - nums[begin] > 1) {
                begin++;
            }
            if (nums[end] - nums[begin] == 1) {
                res = max(res, end - begin + 1);
            }
        }
        return res;
    }
};