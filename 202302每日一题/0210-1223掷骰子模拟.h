#pragma once
using namespace std;
#include <vector>

/*
    d[i][j][k]表示完成了i次掷骰子,第i次掷的是j,并且已经连续掷了k次j的合法序列数
*/
class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int dieSimulator(int n, vector<int>& rollMax) {
        vector d(n + 1, vector(6, vector<int>(16)));
        for (int j = 0; j < 6; j++)
        {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 1; k <= rollMax[j]; k++)
                {
                    //上一次投掷的状态为d[i - 1][j][k]
                    for (int p = 0; p < 6; p++)
                    {
                        if (p != j)
                        {
                            d[i][p][1] = (d[i - 1][j][k] + d[i][p][1]) % mod;
                        }
                        else if (k + 1 <= rollMax[j])
                        {
                            d[i][p][k + 1] = (d[i - 1][j][k] + d[i][p][k + 1]) % mod;
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int j = 0; j < 6; j++)
        {
            for (int k = 1; k <= rollMax[j]; k++)
            {
                res = (res + d[n][j][k]) % mod;
            }
        }
        return res;
    }
};