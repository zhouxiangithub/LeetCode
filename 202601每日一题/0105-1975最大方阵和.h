#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0; // 所有元素的绝对值之和
        int cnt = 0; // 负数元素的数量
        int minVal = INT_MAX; // 所有元素的最小绝对值
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minVal = min(minVal, abs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    cnt++;
                }
                sum += abs(matrix[i][j]);
            }
        }

        if (cnt % 2 == 0) {
            return sum;
        }
        else {
            return sum - 2 * minVal;
        }
    }
};