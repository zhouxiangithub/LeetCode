#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> isGreater(n);
        int preMax = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > preMax) {
                preMax = nums[i];
                isGreater[i] = 1;
            }
        }
        int sufMin = nums[n - 1];
        int res = 0;
        for (int i = n - 2; i > 0; i--) {
            if (isGreater[i] && nums[i] < sufMin) {
                res += 2;
            }
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                res += 1;
            }
            sufMin = min(sufMin, nums[i]);
        }
        return res;
    }
};