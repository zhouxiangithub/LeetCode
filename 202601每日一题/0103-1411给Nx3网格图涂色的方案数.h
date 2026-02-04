#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    int numOfWays(int n) {
        vector<int> types;
        // 预处理相邻格颜色不同的行
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i != j && j != k) {
                        types.push_back(i * 9 + j * 3 + k);
                    }
                }
            }
        }

        int typeSize = types.size();
        vector<vector<int>> related(typeSize, vector<int>(typeSize, 0));
        // 预处理相邻行颜色不同的对
        for (int i = 0; i < typeSize; i++) {
            int x1 = types[i] / 9, x2 = types[i] / 3 % 3, x3 = types[i] % 3;
            for (int j = 0; j < typeSize; j++) {
                int y1 = types[j] / 9, y2 = types[j] / 3 % 3, y3 = types[j] % 3;
                if (x1 != y1 && x2 != y2 && x3 != y3) {
                    related[i][j] = 1;
                }
            }
        }

        vector<vector<int>> f(n, vector<int>(typeSize));
        for (int i = 0; i < typeSize; i++) {
            f[0][i] = 1;
        }
        for (int row = 1; row < n; row++) {
            for (int j = 0; j < typeSize; j++) {
                for (int k = 0; k < typeSize; k++) {
                    if (related[j][k]) {
                        f[row][j] += f[row - 1][k];
                        f[row][j] %= mod;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < typeSize; i++) {
            res += f[n - 1][i];
            res %= mod;
        }
        return res;
    }
};