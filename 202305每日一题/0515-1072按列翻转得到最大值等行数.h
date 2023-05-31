#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> map;
        for (int i = 0; i < m; i++)
        {
            string s = string(n, '0');
            for (int j = 0; j < n; j++)
            {
                //如果matrix[i][0]为1,则对该行元素进行翻转
                s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
            }
            map[s]++;
        }
        int res = 0;
        for (auto& [k, v] : map)
        {
            res = max(res, v);
        }
        return res;
    }
};