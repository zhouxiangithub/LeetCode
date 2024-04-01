#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    vector<int> count;

    int dp(vector<int>& coins, int rem)
    {
        if (rem < 0)
        {
            return -1;
        }
        if (rem == 0)
        {
            return 0;
        }
        if (count[rem - 1] != 0)
        {
            return count[rem - 1];
        }
        int min = INT_MAX;
        for (int coin : coins)
        {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < min)
            {
                min = res + 1;
            }
        }
        count[rem - 1] = min == INT_MAX ? -1 : min;
        return count[rem - 1];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
        {
            return 0;
        }
        count.resize(amount);
        return dp(coins, amount);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};