#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (0 == nums[i]) {
                swap(nums[ptr], nums[i]);
                ptr++;
            }
        }
        for (int i = ptr; i < n; i++) {
            if (1 == nums[i]) {
                swap(nums[ptr], nums[i]);
                ptr++;
            }
        }
    }
};