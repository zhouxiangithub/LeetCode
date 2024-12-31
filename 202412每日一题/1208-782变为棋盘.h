#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int getMoves(int mask, int count, int n) {
        int ones = __builtin_popcount(mask);
        if (n & 1) {
            // ��� n Ϊ����, ��ÿһ���� 1 �� 0 ����Ŀ���Ϊ 1, �����������н���
            if (abs(n - 2 * ones) != 1 || abs(n - 2 * count) != 1) {
                return -1;
            }
            if (ones == (n >> 1)) {
                // ż��λ��Ϊ 1 ����С��������
                // (1010 1010 1010 1010 1010 1010 1010 1010) = 0xAAAAAAAA
                return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            }
            else {
                // ����λ��Ϊ 1 ����С��������
                // (0101 0101 0101 0101 0101 0101 0101 0101) = 0x55555555
                return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
            }
        }
        else {
            // ��� n Ϊż��, ��ÿһ���� 1 �� 0 ����Ŀ��ͬ, �����������н���
            if (ones != (n >> 1) || count != (n >> 1)) {
                return -1;
            }
            int count0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            int count1 = n / 2 - __builtin_popcount(mask & 0x55555555);
            return min(count0, count1);
        }
    }

    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int rowMask = 0, colMask = 0;

        // ��¼��һ�����һ�м���ֱ��Ӧ�ķ���
        for (int i = 0; i < n; i++) {
            rowMask |= (board[0][i] << i);
            colMask |= (board[i][0] << i);
        }
        int reverseRowMask = ((1 << n) - 1) ^ rowMask;
        int reverseColMask = ((1 << n) - 1) ^ colMask;

        int rowCnt = 0, colCnt = 0;
        for (int i = 0; i < n; i++) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; j++) {
                curRowMask |= (board[i][j] << j);
                curColMask |= (board[j][i] << j);
            }

            if (curRowMask != rowMask && curRowMask != reverseRowMask) {
                // ��ǰ�мȲ����һ����ͬҲ�����䷴����ͬ
                return -1;
            }
            else if (curRowMask == rowMask) {
                // ���һ����ͬ������
                rowCnt++;
            }

            if (curColMask != colMask && curColMask != reverseColMask) {
                return -1;
            }
            else if (curColMask == colMask) {
                colCnt++;
            }
        }

        int rowMoves = getMoves(rowMask, rowCnt, n);
        int colMoves = getMoves(colMask, colCnt, n);
        return (rowMoves == -1 || colMoves == -1) ? -1 : (rowMoves + colMoves);
    }
};