#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        unordered_map<int, bool> ump;
        
        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]] = true;
        }

        for (int i = 0; i < moveFrom.size(); i++) {
            ump.erase(moveFrom[i]);
            ump[moveTo[i]] = true;
        }

        for (const auto& [key, _] : ump) {
            ans.push_back(key);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};