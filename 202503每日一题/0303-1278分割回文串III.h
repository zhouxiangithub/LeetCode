#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int cost(string& s, int l, int r) {
        int res = 0;
        for (int i = l, j = r; i < j; i++, j--) {
            if (s[i] != s[j]) {
                res++;
            }
        }
        return res;
    }

    int palindromePartition(string& s, int k) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX)); // 前 i 个字符分成 j 个子串
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(k, i); j++) {
                if (j == 1) {
                    f[i][j] = cost(s, 0, i - 1);
                }
                else {
                    for (int m = j - 1; m < i; m++) {
                        f[i][j] = min(f[i][j], f[m][j - 1] + cost(s, m, i - 1));
                    }
                }
            }
        }
        return f[n][k];
    }
};