#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int res = 0;

        while (nums.size() > 1) {
            bool flag = true;
            int minSum = INT_MAX;
            int index = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    flag = false;
                }

                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            if (flag) {
                break;
            }

            res++;
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
        }

        return res;
    }
};