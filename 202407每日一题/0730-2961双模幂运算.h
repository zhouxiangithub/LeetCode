#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int pow_mod(int x, int y, int mod) {
        int res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            auto& var = variables[i];
            if (pow_mod(pow_mod(var[0], var[1], 10), var[2], var[3]) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};