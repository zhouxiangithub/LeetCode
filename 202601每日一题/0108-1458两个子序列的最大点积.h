#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> f(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mul = nums1[i] * nums2[j];
                f[i][j] = mul;
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                }
                if (i > 0 && j > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + mul);
                }
            }
        }

        return f[m - 1][n - 1];
    }
};