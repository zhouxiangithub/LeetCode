#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        //int n = nums.size();
        //for (int i = 0; i < n; i++) {
        //    if (nums[i] == 0) {
        //        for (int j = i; j < n; j++) {
        //            nums[j] ^= 1;
        //        }
        //        ans++;
        //    }
        //}
        for (int num : nums) {
            if (num == (ans % 2)) {
                ans++;
            }
        }
        return ans;
    }
};