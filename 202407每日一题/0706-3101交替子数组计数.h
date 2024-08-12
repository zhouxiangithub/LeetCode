#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0, cur = 0;
        int pre = -1;
        for (int num : nums) {
            cur = (num != pre) ? cur + 1 : 1;
            pre = num;
            res += cur;
        }
        return res;
    }
};