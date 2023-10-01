#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& operation : operations)
        {
            int x = operation[0], y = operation[1];
            int num = gem[x] / 2;
            gem[x] -= num;
            gem[y] += num;
        }
        int min = *min_element(gem.begin(), gem.end());
        int max = *max_element(gem.begin(), gem.end());
        return max - min;
    }
};