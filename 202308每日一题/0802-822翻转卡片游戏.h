#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = 3000, n = fronts.size();
        unordered_set<int> same;
        unordered_map<int, vector<int>> val_idx;
        for (int i = 0; i < n; i++)
        {
            if (fronts[i] == backs[i])
            {
                same.insert(fronts[i]);
            }
        }
        for (int& x : fronts)
        {
            if (x < res && same.count(x) == 0)
            {
                res = x;
            }
        }
        for (int& x : backs)
        {
            if (x < res && same.count(x) == 0)
            {
                res = x;
            }
        }
        return res % 3000;
    }
};