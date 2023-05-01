#pragma once
using namespace std;
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int x, int y)
            {
                return heights[x] > heights[y];
            });
        vector<string> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = names[index[i]];
        }
        return res;
    }
};