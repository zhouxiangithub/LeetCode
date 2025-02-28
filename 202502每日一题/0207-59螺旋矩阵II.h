#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<vector<int>> dir = { {0,1},{1,0},{0,-1},{-1,0} }; // сробвСио

        int maxNum = n * n;
        int curNum = 1;
        int row = 0, col = 0;
        int index = 0;

        while (curNum <= maxNum) {
            matrix[row][col] = curNum;
            curNum++;
            int nextRow = row + dir[index][0], nextCol = col + dir[index][1];
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || matrix[nextRow][nextCol] != 0) {
                index = (index + 1) % 4;
            }
            row += dir[index][0];
            col += dir[index][1];
        }
        return matrix;
    }
};