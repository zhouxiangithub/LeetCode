#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long ma = *max_element(milestones.begin(), milestones.end());
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - ma;
        if (ma > rest + 1) {
            return 2 * rest + 1;
        }
        else
        {
            return ma + rest;
        }
    }
};