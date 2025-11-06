#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                res.push_back(num);
            }
        }
        return res;
    }
};