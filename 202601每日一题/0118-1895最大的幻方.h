#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> rowSum(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }

        vector<vector<int>> colSum(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
            }
        }

        // 从大到小枚举幻方的边长
        for (int k = min(m, n); k >= 2; k--) {
            // 幻方左上角的点 (i,j)
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum = rowSum[i][j + k - 1] - (j ? rowSum[i][j - 1] : 0);
                    bool check = true;

                    // 每一行
                    for (int nextI = i + 1; nextI <= i + k - 1; nextI++) {
                        if (rowSum[nextI][j + k - 1] - (j ? rowSum[nextI][j - 1] : 0) != sum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }

                    // 每一列
                    for (int nextJ = j; nextJ <= j + k - 1; nextJ++) {
                        if (colSum[i + k - 1][nextJ] - (i ? colSum[i - 1][nextJ] : 0) != sum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }

                    // 对角线
                    int d1 = 0, d2 = 0;
                    for (int dt = 0; dt < k; dt++) {
                        d1 += grid[i + dt][j + dt];
                        d2 += grid[i + dt][j - dt + k - 1];
                    }
                    if (d1 == sum && d2 == sum) {
                        return k;
                    }
                }
            }
        }

        return 1;
    }
};