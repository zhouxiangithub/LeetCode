#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    static constexpr double EPS = 1e-7; // 可忽略误差
    static constexpr double INF = 1e20;

public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        // f[i][j] 表示经过了 dist[0] 到 dist[i−1] 的 i 段道路并且跳过了 j 次的最短用时
        vector<vector<double>> f(n + 1, vector<double>(n + 1, INF)); 
        f[0][0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j != i) { // 不跳过
                    f[i][j] = min(f[i][j], ceil(f[i - 1][j] + (double)dist[i - 1] / speed - EPS));
                }
                if (j != 0) { // 跳过
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + (double)dist[i - 1] / speed);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            if (f[n][j] < hoursBefore + EPS) {
                return j;
            }
        }
        return -1;
    }
};