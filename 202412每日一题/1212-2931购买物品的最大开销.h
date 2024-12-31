#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    using tup = tuple<int, int, int>;
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        priority_queue<tup, vector<tup>, greater<tup>> q;
        for (int i = 0; i < m; i++) {
            q.emplace(values[i][n - 1], i, n - 1);
        }

        long long ans = 0;
        for (int day = 1; day <= m * n; day++) {
            auto [val, i, j] = q.top();
            q.pop();
            ans += static_cast<long long>(val) * day;
            if (j > 0) {
                q.emplace(values[i][j - 1], i, j - 1);
            }
        }
        return ans;
    }
};