#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> ans;

public:
    bool check(int mask, int k, int n) {
        tmp.clear();
        for (int i = 0; i < 9; i++) {
            if ((1 << i) & mask) {
                tmp.push_back(i + 1);
            }
        }
        return tmp.size() == k && accumulate(tmp.begin(), tmp.end(), 0) == n;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int mask = 0; mask < (1 << 9); mask++) {
            if (check(mask, k, n)) {
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};