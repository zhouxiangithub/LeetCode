#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prerow(m, vector<int>(n));
        vector<vector<int>> precol(m, vector<int>(n));
        vector<vector<int>> f(m, vector<int>(n, INT_MIN)); // f(i,j) ��ʾ�� (i,j) ���������÷�
        int res = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    f[i][j] = max(f[i][j], grid[i][j] + precol[i - 1][j]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], grid[i][j] + prerow[i][j - 1]);
                }
                res = max(res, f[i][j]);
                prerow[i][j] = precol[i][j] = max(f[i][j], 0) - grid[i][j];
                if (i > 0) {
                    precol[i][j] = max(precol[i][j], precol[i - 1][j]); // ֵԽ�� ����ԽС
                }
                if (j > 0) {
                    prerow[i][j] = max(prerow[i][j], prerow[i][j - 1]);
                }
            }
        }
        return res;
    }
};