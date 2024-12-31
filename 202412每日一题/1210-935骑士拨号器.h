#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int knightDialer(int n) {
        vector<vector<int>> moves = { {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4} };
        vector<vector<int>> d(2, vector<int>(10, 0));
        fill(d[1].begin(), d[1].end(), 1);
        for (int i = 2; i <= n; i++) {
            int x = i & 1;
            for (int j = 0; j < 10; j++) {
                d[x][j] = 0;
                for (int k : moves[j]) {
                    d[x][j] = (d[x][j] + d[x ^ 1][k]) % mod;
                }
            }
        }
        int res = 0;
        for (auto x : d[n % 2]) {
            res = (res + x) % mod;
        }
        return res;
    }
};

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        vector<vector<long>> dp(n, vector<long>(10, 1));

        for (int i = 1; i < n; i++) {
            dp[i][0] = ((dp[i - 1][4]) % mod + (dp[i - 1][6]) % mod) % mod;
            dp[i][1] = ((dp[i - 1][6]) % mod + (dp[i - 1][8]) % mod) % mod;
            dp[i][2] = ((dp[i - 1][7]) % mod + (dp[i - 1][9]) % mod) % mod;
            dp[i][3] = ((dp[i - 1][4]) % mod + (dp[i - 1][8]) % mod) % mod;
            dp[i][4] = ((dp[i - 1][3]) % mod + (dp[i - 1][9]) % mod + (dp[i - 1][0]) % mod) % mod;
            dp[i][6] = ((dp[i - 1][1]) % mod + (dp[i - 1][7]) % mod + (dp[i - 1][0]) % mod) % mod;
            dp[i][7] = ((dp[i - 1][2]) % mod + (dp[i - 1][6]) % mod) % mod;
            dp[i][8] = ((dp[i - 1][1]) % mod + (dp[i - 1][3]) % mod) % mod;
            dp[i][9] = ((dp[i - 1][2]) % mod + (dp[i - 1][4]) % mod) % mod;
        }

        long ans = 0;
        dp[n - 1][5] = 0;

        for (int j = 0; j < 10; j++) {
            ans += (dp[n - 1][j] % mod);
        }

        return (int)(ans % mod);
    }
};