#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1 << n, INT_MAX);
        vector<int> need(1 << n, 0);
        for (auto& edge : relations) {
            need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
        }
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            need[i] = need[i & (i - 1)] | need[i & (-i)];
            if ((need[i] | i) != i) { // i 中有任意一门课程的前置课程没有完成学习
                continue;
            }
            int valid = i ^ need[i]; // 当前学期可以进行学习的课程集合
            if (__builtin_popcount(valid) <= k) { // 如果个数小于 k，则可以全部学习，不再枚举子集
                dp[i] = min(dp[i], dp[i ^ valid] + 1);
            }
            else { // 否则枚举当前学期需要进行学习的课程集合
                for (int sub = valid; sub; sub = (sub - 1) & valid) {
                    if (__builtin_popcount(sub) <= k) {
                        dp[i] = min(dp[i], dp[i ^ sub] + 1);
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};