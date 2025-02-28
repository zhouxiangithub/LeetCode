#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        // dp[i][j] 前 i 块砖使用了 j 个地毯后未被覆盖的白色砖块数
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, INF));
        for (int j = 0; j <= numCarpets; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1');
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; j++) {
                dp[i][j] = dp[i - 1][j] + (floor[i - 1] == '1');
                dp[i][j] = min(dp[i][j], dp[max(0, i - carpetLen)][j - 1]);
            }
        }
        return dp[n][numCarpets];
    }
};

class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        vector<int> dp(n + 1, INF), f(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (floor[i - 1] == '1');
        }
        for (int j = 1; j <= numCarpets; j++) {
            f[0] = 0;
            for (int i = 1; i <= n; i++) {
                f[i] = f[i - 1] + (floor[i - 1] == '1');
                f[i] = min(f[i], dp[max(0, i - carpetLen)]);
            }
            swap(dp, f);
        }
        return dp[n];
    }
};