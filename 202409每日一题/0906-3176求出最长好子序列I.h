#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp; // dp[i][j] ��ʾ�� nums[i] ��β��ɵ���Ϸ��������� j �����������������еĺ�һ�����ֲ����
        dp.resize(n, vector<int>(25, -1));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < i; x++) {
                    int add = (nums[x] != nums[i]);
                    if (j >= add && dp[x][j - add] != -1) {
                        dp[i][j] = max(dp[i][j], dp[x][j - add] + 1);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};