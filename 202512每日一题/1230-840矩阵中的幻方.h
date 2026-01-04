#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    bool isMagicSquare(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
        vector<int> vals = { a0, a1, a2, a3, a4, a5, a6, a7, a8 };
        vector<int> freq(16, 0);
        for (int val : vals) {
            if (val < 1 || val>9) {
                return false;
            }
            freq[val]++;
        }

        for (int num = 1; num <= 9; num++) {
            if (freq[num] != 1) {
                return false;
            }
        }

        return (a0 + a1 + a2 == 15 && a3 + a4 + a5 == 15 && a6 + a7 + a8 == 15
            && a0 + a3 + a6 == 15 && a1 + a4 + a7 == 15 && a2 + a5 + a8 == 15
            && a0 + a4 + a8 == 15 && a2 + a4 + a6 == 15);
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        for (int r = 0; r < row - 2; r++) {
            for (int c = 0; c < col - 2; c++) {
                if (grid[r + 1][c + 1] != 5) {
                    continue;
                }
                if (isMagicSquare(grid[r][c], grid[r][c + 1], grid[r][c + 2],
                    grid[r + 1][c], grid[r + 1][c + 1], grid[r + 1][c + 2],
                    grid[r + 2][c], grid[r + 2][c + 1], grid[r + 2][c + 2])) {
                    res++;
                }
            }
        }
        return res;
    }
};