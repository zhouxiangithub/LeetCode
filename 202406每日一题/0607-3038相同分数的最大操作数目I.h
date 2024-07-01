#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int res = 0;
        int num = nums[0] + nums[1];
        for (int i = 1; i < nums.size(); i += 2) {
            if (nums[i - 1] + nums[i] != num) {
                break;
            }
            res++;
        }
        return res;
    }
};