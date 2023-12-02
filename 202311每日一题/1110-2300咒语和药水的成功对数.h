#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
            });
        sort(potions.begin(), potions.end(), [](int a, int b)
            {
                return a > b;
            });
        for (int i = 0, j = 0; i < idx.size(); i++)
        {
            int p = idx[i];
            int v = spells[p];
            while (j < potions.size() && (long long)v * potions[j] >= success)
            {
                j++;
            }
            res[p] = j;
        }
        return res;
    }
};