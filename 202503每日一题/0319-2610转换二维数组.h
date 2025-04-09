#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }

        vector<vector<int>> ans;
        while (!cnt.empty()) {
            vector<int> arr;
            for (auto it = cnt.begin(); it != cnt.end(); ) {
                it->second--;
                arr.emplace_back(it->first);
                if (it->second == 0) {
                    it = cnt.erase(it);
                }
                else {
                    it++;
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};