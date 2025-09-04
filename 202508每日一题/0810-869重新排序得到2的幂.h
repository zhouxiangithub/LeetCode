#pragma once
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

class Solution {
    vector<int> vis;

    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    bool helper(string& nums, int idx, int num) {
        if (idx == nums.length()) {
            return isPowerOfTwo(num);
        }
        for (int i = 0; i < nums.length(); i++) {
            if ((num == 0 && nums[i] == '0') || vis[i] || (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            vis[i] = 1;
            if (helper(nums, idx + 1, num * 10 + nums[i] - '0')) {
                return true;
            }
            vis[i] = 0;
        }
        return false;
    }

public:
    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        vis.resize(nums.length());
        return helper(nums, 0, 0);
    }
};