#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        unordered_set<int> cnt;
        for (int num : nums) {
            if (cnt.find(num) != cnt.end()) {
                res ^= num;
            }
            else {
                cnt.emplace(num);
            }
        }
        return res;
    }
};