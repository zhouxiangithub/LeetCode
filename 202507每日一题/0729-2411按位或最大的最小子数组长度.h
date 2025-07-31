#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pos(31, -1);
        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            for (int bit = 0; bit < 31; bit++) {
                if (!(nums[i] & (1 << bit))) {
                    if (pos[bit] != -1) {
                        j = max(j, pos[bit]);
                    }
                }
                else {
                    pos[bit] = i;
                }
            }
            res[i] = j - i + 1;
        }
        return res;
    }
};