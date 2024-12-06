#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            // �� mid Ϊż��, �Ƚ� nums[mid] �� nums[mid+1]
            // �� mid Ϊ����, �Ƚ� nums[mid] �� nums[mid-1]
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