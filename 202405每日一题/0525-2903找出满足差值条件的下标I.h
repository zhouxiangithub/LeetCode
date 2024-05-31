#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int minValIdx = 0, maxValIdx = 0;
        for (int j = indexDifference; j < nums.size(); j++) {
            int i = j - indexDifference;
            if (nums[i] < minValIdx) {
                minValIdx = i;
            }
            if (abs(nums[minValIdx] - nums[j]) >= valueDifference) {
                return { minValIdx,j };
            }
            if (nums[i] > maxValIdx) {
                maxValIdx = i;
            }
            if (abs(nums[maxValIdx] - nums[j]) >= valueDifference) {
                return { maxValIdx,j };
            }
        }
        return { -1,-1 };
    }
};