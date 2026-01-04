#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < k; i++) {
            res += max(happiness[i] - i, 0);
        }
        return res;
    }
};