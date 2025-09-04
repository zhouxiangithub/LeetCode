#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    bool rows[9][9];
    bool cols[9][9];
    bool subMats[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        for (int idx = 0; idx < 9 && !valid; idx++) {
            if (!rows[i][idx] && !cols[j][idx] && !subMats[i / 3][j / 3][idx]) {
                rows[i][idx] = cols[j][idx] = subMats[i / 3][j / 3][idx] = true;
                board[i][j] = idx + '0' + 1;
                dfs(board, pos + 1);
                rows[i][idx] = cols[j][idx] = subMats[i / 3][j / 3][idx] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(subMats, false, sizeof(subMats));
        valid = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int idx = board[i][j] - '0' - 1;
                    rows[i][idx] = cols[j][idx] = subMats[i / 3][j / 3][idx] = true;
                }
            }
        }

        dfs(board, 0);
    }
};