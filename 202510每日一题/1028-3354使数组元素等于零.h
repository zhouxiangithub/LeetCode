#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    bool isValid(const vector<int>& nums, int nonZeros, int start, int direction) {
        int n = nums.size();
        vector<int> temp(nums);
        int curr = start;

        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) {
                    nonZeros--;
                }
            }
            curr += direction;
        }

        return nonZeros == 0;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int nonZeros = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nonZeros++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) {
                    res++;
                }
                if (isValid(nums, nonZeros, i, 1)) {
                    res++;
                }
            }
        }

        return res;
    }
};