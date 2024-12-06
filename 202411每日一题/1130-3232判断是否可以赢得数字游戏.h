#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, doubleSum = 0;
        for (auto num : nums) {
            if (num < 10) {
                singleSum += num;
            }
            else {
                doubleSum += num;
            }
        }
        return singleSum != doubleSum;
    }
};