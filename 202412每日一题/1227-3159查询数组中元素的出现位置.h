#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indexs;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                indexs.emplace_back(i);
            }
        }

        vector<int> res;
        for (int query : queries) {
            if (query > indexs.size()) {
                res.emplace_back(-1);
            }
            else {
                res.emplace_back(indexs[query - 1]);
            }
        }
        return res;
    }
};