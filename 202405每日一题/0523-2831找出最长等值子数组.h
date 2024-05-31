#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> posMap; //value--index
        for (int i = 0; i < n; i++) {
            posMap[nums[i]].emplace_back(i);
        }
        int ans = 0;
        for (auto& [_, idxVec] : posMap) {
            for (int i = 0, j = 0; i < idxVec.size(); i++) {
                while ((idxVec[i] - idxVec[j]) - (i - j) > k) {
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};