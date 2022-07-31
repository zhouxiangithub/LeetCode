#pragma once
using namespace std;
#include <vector>

/*
    由于从(n-1,n-1)返回(0,0)的这条路径，可以等价地看成从(0,0)到(n-1,n-1)的路径
    因此问题可以等价于：有两个人从(0,0)出发，向下或向右走到(n-1,n-1)时，摘到的樱桃个数之和的最大值
    当然，同一个格子只能摘取一次

    在时间速度相同情况下，两人向右加向下走的步数之和是定值，设为k，则：x1+y1=x2+y2=k
    定义f[k][x1][x2]表示两人A和B分别从(x1,k-x1)和(x2,k-x2)同时出发，到达(n-1,n-1)摘到的樱桃个数之和的最大值

    枚举两人上一步的走法：
    1. 都往右：f[k-1][x1][x2]
    2. A往下，B往右：f[k-1][x1-1][x2]
    3. A往右，B往下：f[k-1][x1][x2-1]
    4. 都往下：f[k-1][x1-1][x2-1]
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(2 * n - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; k++)
        {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); x1++)
            {
                int y1 = k - x1;
                if (grid[x1][y1] == -1)
                {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); x2++)
                {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1)
                    {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; //都往右
                    if (x1)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2]); //往下，往右
                    }
                    if (x2)
                    {
                        res = max(res, f[k - 1][x1][x2 - 1]); //往右，往下
                    }
                    if (x1 && x2)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); //都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) //避免重复摘一个樱桃
                    {
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};