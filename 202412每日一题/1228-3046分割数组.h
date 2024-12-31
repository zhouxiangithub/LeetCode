#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (++count[num] > 2) {
                return false;
            }
        }
        return true;
    }
};