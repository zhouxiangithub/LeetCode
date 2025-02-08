#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int res = 0;
        int idx = n - 2;
        for (int i = 0; i < n / 3; i++) {
            res += piles[idx];
            idx -= 2;
        }
        return res;
    }
};