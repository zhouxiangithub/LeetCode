#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int left = 0;
        while (left < n - 1) {
            if (nums[left] >= nums[left + 1]) {
                break;
            }
            left++;
        }
        if (left == n - 1) {
            return 1LL * n * (n + 1) / 2; //n¸ölen1,n-1¸ölen2,...,1¸ölenn
        }

        ans += left + 2;
        for (int right = n - 1; right > 0; right--) {
            if (right < n - 1 && nums[right] >= nums[right + 1]) {
                break;
            }
            while (left >= 0 && nums[left] >= nums[right]) {
                left--;
            }
            ans += left + 2; //[left+1,right-1],[left,right-1],...,[0,right-1]
        }
        return ans;
    }
};