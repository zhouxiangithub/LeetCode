#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        //dp[i][m]��ʾǰi��ʯͷ�Ѿ���ȡ��,��ǰ��M=mʱ,������ȡʯͷ����ҿ��Ա���һ����ȡ��ʯͷ��
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
        for (int i = n; i >= 0; i--)
        {
            for (int m = 1; m <= n; m++)
            {
                if (i == n) //ǰn��ʯͷ��ȡ����,���Ե�ǰ��ҿ��Ա���һ����ȡ��ʯͷ��Ϊ0
                {
                    dp[i][m] = 0;
                }
                else
                {
                    int sum = 0;
                    for (int x = 1; x <= 2 * m; x++) //ȡʣ�µ�ǰx��
                    {
                        if (i + x > n)
                        {
                            break;
                        }
                        sum += piles[i + x - 1]; //ȡʣ�µ�ǰx�ѵ�ʯͷ��
                        dp[i][m] = max(dp[i][m], sum - dp[i + x][min(n, max(m, x))]);
                    }
                }
            }
        }
        //�տ���(m=1),Alice�ȿ�ʼ,���Ա�Bob���õ�ʯͷ��Ϊdp[0][1]
        return (dp[0][1] + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};