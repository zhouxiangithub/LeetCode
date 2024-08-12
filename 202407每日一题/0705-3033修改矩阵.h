#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            int cMax = -1;
            for (int i = 0; i < m; i++) {
                cMax = max(cMax, matrix[i][j]);
            }
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = cMax;
                }
            }
        }
        return matrix;
    }
};