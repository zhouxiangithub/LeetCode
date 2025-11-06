#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& spell : spells) {
            long long tmp = (success + spell - 1) / spell - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), tmp) - potions.begin()));
        }
        return res;
    }
};