#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            // 若 mid 为偶数, 比较 nums[mid] 和 nums[mid+1]
            // 若 mid 为奇数, 比较 nums[mid] 和 nums[mid-1]
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};