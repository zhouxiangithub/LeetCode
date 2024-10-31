#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    ��Ϊ���һ�β���ǰ���ܽ���һ��С�ڵ��� maxValue-1
    ���Կɻ�õ�����ܽ���С�ڵ��� 2*maxValue-1
*/
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int maxValue = rewardValues.back();
        vector<int> dp(2 * maxValue); // dp[i] ��ʾ�ܽ��� i �Ƿ�ɻ��
        dp[0] = 1;
        for (int x : rewardValues) { // �������һ�ο���ѡ�����
            for (int k = 2 * x - 1; k >= x; k--) { // �ܽ�����Χ
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