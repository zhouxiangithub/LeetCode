#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0, cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (sum > cnt) {
                cnt = sum;
                row = i;
            }
        }
        return { row,cnt };
    }
};