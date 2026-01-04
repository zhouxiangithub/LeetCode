#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
private:
    vector<vector<int>> T;
    unordered_set<long> Seen;
    vector<vector<int>> A;

    // 当前行的状态编码, 当前处理的行号, 当前行中的位置索引
    bool solve(long state, int row, int idx) {
        if (row == 1 && idx == 1) { // 成功构建到金字塔顶部
            return true;
        }
        else if (idx == row) { // 当前行处理完成,准备处理下一行
            if (Seen.find(state) != Seen.end()) {
                return false;
            }
            Seen.insert(state);
            return solve(0, row - 1, 0);
        }
        else { // 处理当前行的当前位置
            int s = T[A[row][idx]][A[row][idx + 1]];
            for (int i = 0; i < 7; i++) {
                if ((s >> i) & 1) {
                    A[row - 1][idx] = i;
                    if (solve(state * 7 + (i + 1), row, idx + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        T = vector<vector<int>>(6, vector<int>(6, 0)); // 底部为i和j时,顶部可能的字符位掩码
        for (const string& str : allowed) {
            int left = str[0] - 'A';
            int right = str[1] - 'A';
            int top = str[2] - 'A';
            T[left][right] |= 1 << top;
        }

        Seen.clear();
        int n = bottom.length();
        A = vector<vector<int>>(n, vector<int>(n, 0)); // 金字塔状态数组
        for (int i = 0; i < n; i++) {
            A[n - 1][i] = bottom[i] - 'A';
        }

        return solve(0, n - 1, 0);
    }
};