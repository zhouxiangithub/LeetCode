#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size(), res = INT_MAX;
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i += k) {
            string part = word.substr(i, k);
            cnt[part]++;
            res = min(res, n / k - cnt[part]);
        }
        return res;
    }
};