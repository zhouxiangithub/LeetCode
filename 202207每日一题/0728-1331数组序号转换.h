#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> ranks;
        for (auto& a : sortedArr)
        {
            if (!ranks.count(a))
            {
                ranks[a] = ranks.size() + 1;
            }
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};