#pragma once
using namespace std;
#include <vector>

//直接模拟
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int res = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (auto& index : indices)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[index[0]][i]++;
            }
            for (int i = 0; i < m; i++)
            {
                matrix[i][index[1]]++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] & 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};

//模拟空间优化
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m), cols(n); //记录每一行和每一列被增加的次数
        for (auto& index : indices)
        {
            rows[index[0]]++;
            cols[index[1]]++;
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((rows[i] + cols[j]) & 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};