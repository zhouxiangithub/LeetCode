#pragma once
using namespace std;
#include <vector>

/*
    ���ڴ�(n-1,n-1)����(0,0)������·�������Եȼ۵ؿ��ɴ�(0,0)��(n-1,n-1)��·��
    ���������Եȼ��ڣ��������˴�(0,0)���������»������ߵ�(n-1,n-1)ʱ��ժ����ӣ�Ҹ���֮�͵����ֵ
    ��Ȼ��ͬһ������ֻ��ժȡһ��

    ��ʱ���ٶ���ͬ����£��������Ҽ������ߵĲ���֮���Ƕ�ֵ����Ϊk����x1+y1=x2+y2=k
    ����f[k][x1][x2]��ʾ����A��B�ֱ��(x1,k-x1)��(x2,k-x2)ͬʱ����������(n-1,n-1)ժ����ӣ�Ҹ���֮�͵����ֵ

    ö��������һ�����߷���
    1. �����ң�f[k-1][x1][x2]
    2. A���£�B���ң�f[k-1][x1-1][x2]
    3. A���ң�B���£�f[k-1][x1][x2-1]
    4. �����£�f[k-1][x1-1][x2-1]
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
                    int res = f[k - 1][x1][x2]; //������
                    if (x1)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2]); //���£�����
                    }
                    if (x2)
                    {
                        res = max(res, f[k - 1][x1][x2 - 1]); //���ң�����
                    }
                    if (x1 && x2)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); //������
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) //�����ظ�ժһ��ӣ��
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