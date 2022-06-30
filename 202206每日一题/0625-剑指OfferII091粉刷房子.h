#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = 1; i < n; i++)
        {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3);
        //��ֻ�е�0�ŷ��ӱ���ˢʱ������ÿһ����ɫ���ܻ��ѳɱ���Ϊ����0�ŷ��ӷ�ˢ�ɸ���ɫ�Ļ��ѳɱ�
        for (int j = 0; j < 3; j++)
        {
            dp[j] = costs[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> dpNew(3);
            for (int j = 0; j < 3; j++)
            {
                dpNew[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            }
            dp = dpNew;
        }
        return *min_element(dp.begin(), dp.end());
    }
};