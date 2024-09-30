#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0, digSum = 0;
        for (int num : nums) {
            eleSum += num;
            while (num) {
                digSum += num % 10;
                num /= 10;
            }
        }
        return eleSum - digSum;
    }
};