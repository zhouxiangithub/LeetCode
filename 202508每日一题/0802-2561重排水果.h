#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> freq;
        for (int b1 : basket1) {
            freq[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2) {
            freq[b2]--;
            m = min(m, b2);
        }
        vector<int> merge; // ´ý½»»»
        for (auto [k, v] : freq) {
            if (v % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(v) / 2; i++) {
                merge.push_back(k);
            }
        }
        // x1ºÍx2½»»»:1,min(x1, x2);2,2*m;(x1<->m,m<->x2)
        nth_element(merge.begin(), merge.begin() + merge.size() / 2, merge.end());
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0LL,
            [&](long long res, int x)->long long {
                return res + min(x, 2 * m);
            });
    }
};