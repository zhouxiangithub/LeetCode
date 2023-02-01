#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    采用0,1,2对跑道进行编号,因此obstacles[i]-1与跑道对应,值-1表示i点无障碍
    假设d[i][j]表示青蛙到达i号点的j号跑道所需的最少侧跳次数
    由于青蛙从点0处跑道2出发,且点0处和点n处的任一跑道都无障碍
    则: d[0][0]=1, d[0][1]=0, d[0][2]=1
*/
class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<int> d = { 1,0,1 };
        for (int i = 1; i <= n; i++)
        {
            int minCnt = inf;
            //同一条跑道
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1) //有障碍
                {
                    d[j] = inf;
                }
                else
                {
                    minCnt = min(minCnt, d[j]);
                }
            }
            //跨跑道
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i] - 1) //有障碍
                {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};