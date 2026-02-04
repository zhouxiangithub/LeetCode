#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> rec(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                rec[i][j] = rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int left = 1, right = min(m, n), res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= m - mid + 1; i++) {
                for (int j = 1; j <= n - mid + 1; j++) {
                    if (getRect(rec, i, j, i + mid - 1, j + mid - 1) <= threshold) {
                        check = true;
                    }
                }
            }
            if (check) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};