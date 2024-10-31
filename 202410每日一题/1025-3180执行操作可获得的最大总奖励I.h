#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    因为最后一次操作前的总奖励一定小于等于 maxValue-1
    所以可获得的最大总奖励小于等于 2*maxValue-1
*/
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int maxValue = rewardValues.back();
        vector<int> dp(2 * maxValue); // dp[i] 表示总奖励 i 是否可获得
        dp[0] = 1;
        for (int x : rewardValues) { // 遍历最后一次可能选择的数
            for (int k = 2 * x - 1; k >= x; k--) { // 总奖励范围
                if (dp[k - x]) {
                    dp[k] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i]) {
                res = i;
            }
        }
        return res;
    }
};