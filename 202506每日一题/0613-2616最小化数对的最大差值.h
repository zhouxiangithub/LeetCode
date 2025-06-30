#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        auto check = [&](int mx)->bool {
            int cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= mx) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };
        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};