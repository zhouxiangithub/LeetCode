#pragma once
using namespace std;
#include <vector>

// 0 <= i < j < k < l
// nums[i] < nums[k] < nums[j] < nums[l]
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int suf = 0;
            for (int k = n - 1; k > j; k--) {
                if (nums[k] < nums[j]) {
                    ans += static_cast<long long>(pre[nums[k]]) * suf;
                }
                else {
                    suf++;
                }
            }
            // pre[x] 表示 nums[0] 到 nums[j−1] 中小于 x 的元素个数
            for (int x = nums[j] + 1; x <= n; x++) {
                pre[x]++;
            }
        }
        return ans;
    }
};