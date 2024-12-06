#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/**
* f[i][j] 表示在当前待切割的木棍的左端点为 cuts[i−1], 右端点为 cuts[j+1] 时, 将木棍全部切开的最小总成本
* 
* 木棍有 j-i+1 个切割位置 cuts[i],...,cuts[j], 并被切成了 j-i+2 段
* 
* cuts[0]=0, cuts[m+1]=n
*/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> f(m + 2, vector<int>(m + 2));
        for (int i = m; i >= 1; i--) {
            for (int j = i; j <= m; j++) {
                f[i][j] = (i == j ? 0 : INT_MAX);
                for (int k = i; k <= j; k++) {
                    f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j]);
                }
                f[i][j] += cuts[j + 1] - cuts[i - 1];
            }
        }
        return f[1][m];
    }
};