#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty() && stack.back() > num) {
                stack.pop_back();
            }
            if (num == 0) {
                continue;
            }
            if (stack.empty() || stack.back() < num) {
                res++;
                stack.push_back(num);
            }
        }
        return res;
    }
};