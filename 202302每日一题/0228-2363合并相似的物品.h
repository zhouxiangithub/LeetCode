#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto& v1 : items1)
        {
            mp[v1[0]] += v1[1];
        }
        for (auto& v2 : items2)
        {
            mp[v2[0]] += v2[1];
        }
        vector<vector<int>> res;
        for (auto& [k, v] : mp)
        {
            res.push_back({ k,v });
        }
        return res;
    }
};