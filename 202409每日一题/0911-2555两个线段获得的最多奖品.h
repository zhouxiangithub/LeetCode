#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1); // �� dp[i] ��ʾ�Ҷ˵㲻���� prizePositions[i] ���߶ο��Ը������Ʒ����
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