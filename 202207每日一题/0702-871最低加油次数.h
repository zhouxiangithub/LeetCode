#pragma once
using namespace std;
#include <vector>

/*
    dp[i]��ʾ����i�ε������ʻӢ����

    ������������վstations[i]ʱ�������ٵ���ü���վ֮ǰ�Ѿ�����j�Σ�����0<=j<=i
    ��ֻ�е�dp[j]>=stations[i][0]ʱ�����ڼ���j�ε�����´ﵽ����վstations[i]��λ��
    �ڼ���վstations[i]����֮�󣬹�����j+1�Σ�������ʻ��Ӣ������dp[j]+stations[i][1]
    ��������0<=j<=i��dp[j]>=stations[i][0]��ÿ���±�j������dp[j+1]�����ֵ

    ������������վstations[i]ʱ������ÿ������Ҫ����±�j������dp[j+1]ʱ���ǽ�����վstations[i]
    ��Ϊ���һ�μ��͵ļ���վ��Ϊ��ȷ��ÿ��dp[j+1]�ļ����У�����վstations[i]ֻ�ᱻ����һ�Σ�
    Ӧ�ð��մӴ�С��˳������±�j��
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (dp[j] >= stations[i][0])
                {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (dp[i] >= target)
            {
                return i;
            }
        }
        return -1;
    }
};