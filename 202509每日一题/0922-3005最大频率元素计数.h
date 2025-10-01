#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int maxFreq = 0;
        for (auto const& pair : count) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }
        int res = 0;
        for (auto const& pair : count) {
            if (pair.second == maxFreq) {
                res += maxFreq;
            }
        }
        return res;
    }
};