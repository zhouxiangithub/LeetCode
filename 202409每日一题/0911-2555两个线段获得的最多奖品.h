#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1); // 设 dp[i] 表示右端点不超过 prizePositions[i] 的线段可以覆盖最大奖品数量
        int ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            ans = max(ans, right - left + 1 + dp[left]);
            dp[right + 1] = max(dp[right], right - left + 1);
        }
        return ans;
    }
};