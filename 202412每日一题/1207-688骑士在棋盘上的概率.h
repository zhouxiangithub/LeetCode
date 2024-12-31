#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> dirs = { {-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2} };

    double knightProbability(int n, int k, int row, int column) {
        // dp[step][i][j] 表示从 (i,j) 出发, 走了 step 步时仍留在棋盘上的概率
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    }
                    else {
                        for (auto& dir : dirs) {
                            int di = i + dir[0], dj = j + dir[1];
                            if (di >= 0 && di < n && dj >= 0 && dj < n) {
                                dp[step][i][j] += dp[step - 1][di][dj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};