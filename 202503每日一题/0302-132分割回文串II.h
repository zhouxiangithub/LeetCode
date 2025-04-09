#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        vector<int> g(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (f[0][i]) {
                g[i] = 0;
            }
            else {
                for (int j = 0; j < i; j++) {
                    if (f[j + 1][i]) {
                        g[i] = min(g[i], g[j] + 1);
                    }
                }
            }
        }
        return g[n - 1];
    }
};