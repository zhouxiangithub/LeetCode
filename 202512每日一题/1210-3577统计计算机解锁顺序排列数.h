#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]) {
            return 0;
        }

        // (n-1)!
        int res = 1;
        for (int i = 2; i < n; i++) {
            res = static_cast<long long>(res) * i % MOD;
        }
        return res;
    }
};