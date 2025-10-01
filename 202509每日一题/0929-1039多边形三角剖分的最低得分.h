#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int > memo;
        int n = values.size();
        // dp[i][j] (j>=i+2) 为顶点 i,i+1,...,j-1,j 构成的凸 j-i+1 边形进行三角形剖分后可以得到的最低分
        function<int(int, int)> dp = [&](int i, int j)->int {
            if (j < i + 2) {
                return 0;
            }
            if (j == i + 2) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[j] * values[k] + dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};