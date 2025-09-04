#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int subMats[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(subMats, 0, sizeof(subMats));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int idx = c - '0' - 1;
                    rows[i][idx]++;
                    cols[j][idx]++;
                    subMats[i / 3][j / 3][idx]++;
                    if (rows[i][idx] > 1 || cols[j][idx] > 1 || subMats[i / 3][j / 3][idx] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};