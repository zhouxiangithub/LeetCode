#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> uMap;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            int val = nums[j];
            for (int i : uMap[val]) {
                if ((i * j) % k == 0) {
                    ans++;
                }
            }
            uMap[val].push_back(j);
        }
        return ans;
    }
};