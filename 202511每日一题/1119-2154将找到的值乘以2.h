#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> uSet(nums.begin(), nums.end());
        while (uSet.count(original)) {
            original *= 2;
        }
        return original;
    }
};