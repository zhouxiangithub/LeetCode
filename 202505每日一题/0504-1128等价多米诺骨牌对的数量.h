#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mCount;
        for (auto& dom : dominoes) {
            mCount[{min(dom[0], dom[1]), max(dom[0], dom[1])}]++;
        }
        int res = 0;
        for (auto& [_, v] : mCount) {
            res += v * (v - 1) / 2;
        }
        return res;
    }
};