#pragma once
using namespace std;
#include <vector>

/*
    定义 f[i] 表示从奇数次到房间 i 到奇数次到达房间 i+1 所需要的天数
    记 to = nextVisit[i]
    得 f[i] = f[to] + f[to+1] + ... + f[i-1] + 2

    定义 dp[i] 表示从 0 号房间出发首次到 i+1 花费的天数

    则 dp[i] = f[0] + f[1] + ... + f[i]
    
    ==> dp[i] - dp[i-1] = f[i] = f[to] + f[to+1] + ... + f[i-1] + 2 = dp[i-1] - dp[to-1] + 2

    即 dp[i] - dp[i-1] = dp[i-1] - dp[to-1] + 2
    求 dp[n-2]
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