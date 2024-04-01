#pragma once
using namespace std;
#include <vector>

/*
    ���� f[i] ��ʾ�������ε����� i �������ε��﷿�� i+1 ����Ҫ������
    �� to = nextVisit[i]
    �� f[i] = f[to] + f[to+1] + ... + f[i-1] + 2

    ���� dp[i] ��ʾ�� 0 �ŷ�������״ε� i+1 ���ѵ�����

    �� dp[i] = f[0] + f[1] + ... + f[i]
    
    ==> dp[i] - dp[i-1] = f[i] = f[to] + f[to+1] + ... + f[i-1] + 2 = dp[i-1] - dp[to-1] + 2

    �� dp[i] - dp[i-1] = dp[i-1] - dp[to-1] + 2
    �� dp[n-2]
*/
class Solution {
private:
    static constexpr int mod = 1e9 + 7;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<int> dp(n);

        dp[0] = 2;
        for (int i = 1; i < n; i++)
        {
            int to = nextVisit[i];
            dp[i] = dp[i - 1] + 2;
            if (to != 0)
            {
                dp[i] = (dp[i] - dp[to - 1] + mod) % mod;
            }
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        return dp[n - 2];
    }
};