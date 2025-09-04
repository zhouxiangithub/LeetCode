#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    f[i][j] = mat[i][j];
                }
                else {
                    f[i][j] = (mat[i][j] == 0) ? 0 : f[i][j - 1] + 1;
                }
                int cur = f[i][j];
                for (int k = i; k >= 0; k--) {
                    cur = min(cur, f[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
};