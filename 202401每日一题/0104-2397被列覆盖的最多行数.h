#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> mask(m, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mask[i] += matrix[i][j] << (n - 1 - j);
            }
        }

        int res = 0;
        int cur = 0;
        while ((++cur) < (1 << n))
        {
            if (__builtin_popcount(cur) != numSelect)
            {
                continue;
            }
            int row_cnt = 0;
            for (int k = 0; k < m; k++)
            {
                if ((mask[k] & cur) == mask[k])
                {
                    row_cnt++;
                }
            }
            res = max(res, row_cnt);
        }

        return res;
    }
};