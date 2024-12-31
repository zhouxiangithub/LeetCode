#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt = 0, posRx = 0, posRy = 0;
        int dx[4] = { 0,1,0,-1 };
        int dy[4] = { 1,0,-1,0 };
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    posRx = i;
                    posRy = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int step = 0;; step++) {
                int tx = posRx + step * dx[i];
                int ty = posRy + step * dy[i];
                if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') {
                    break;
                }
                if (board[tx][ty] == 'p') {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};