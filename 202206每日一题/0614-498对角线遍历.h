#pragma once
using namespace std;
#include <vector>

/*
    一共有 m+n-1 条对角线：
    相邻的对角线的遍历方向不同，当前：左下->右上，下一条：右上->左下

    假设对角线从上到下的编号为：[0, m+n-2]
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++)
        {
            if (i % 2) //奇数：右上->左下
            {
                int x = i < n ? 0 : (i - n + 1);
                int y = i < n ? i : (n - 1);
                while (x < m && y >= 0)
                {
                    res.emplace_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            else //偶数：左下->右上
            {
                int x = i < m ? i : (m - 1);
                int y = i < m ? 0 : (i - m + 1);
                while (x >= 0 && y < n)
                {
                    res.emplace_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
};