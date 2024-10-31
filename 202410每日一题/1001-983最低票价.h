#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366]; // ��i�����ε������,[1,i]������ӵ���С����
        memset(dp, 0, sizeof(dp));
        int n = days.size();
        dp[0] = 0;
        for (int i = 1, j = 0; i <= 365 && j < n; i++) {
            dp[i] = dp[i - 1]; // ��i�첻����
            if (i == days[j]) { // ��i������
                dp[i] = dp[max(0, i - 1)] + costs[0];
                dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
                j++;
            }
        }
        return dp[days.back()];
    }
};