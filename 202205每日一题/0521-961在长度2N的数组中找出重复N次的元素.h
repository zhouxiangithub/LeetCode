#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> found;
        for (int num : nums)
        {
            if (found.count(num))
            {
                return num;
            }
            found.insert(num);
        }
        return -1;
    }
};