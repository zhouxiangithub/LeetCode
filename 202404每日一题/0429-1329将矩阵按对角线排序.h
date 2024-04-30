#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> diag(m + n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j + n].push_back(mat[i][j]);
            }
        }
        for (auto& d : diag) {
            sort(d.rbegin(), d.rend());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = diag[i - j + n].back();
                diag[i - j + n].pop_back();
            }
        }
        return mat;
    }
};