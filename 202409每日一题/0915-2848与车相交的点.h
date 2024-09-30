#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ma = 0;
        for (const auto& interval : nums) {
            ma = max(ma, interval[1]);
        }

        vector<int> count(ma + 1);
        for (const auto& interval : nums) {
            for (int i = interval[0]; i <= interval[1]; i++) {
                count[i]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= ma; i++) {
            if (count[i]) {
                ans++;
            }
        }

        return ans;
    }
};