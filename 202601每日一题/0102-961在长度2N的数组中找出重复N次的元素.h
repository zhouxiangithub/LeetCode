#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> uSet;
        for (int num : nums) {
            if (uSet.count(num)) {
                return num;
            }
            uSet.insert(num);
        }
        return -1;
    }
};