#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> people;
        for (int i = 0; i < n; i++)
        {
            people.push_back({ scores[i],ages[i] });
        }
        sort(people.begin(), people.end());
        //dp[i]为最后组建的球队中的最大球员序号为排序后的第i名球员时的球队最大分数
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (people[j].second <= people[i].second)
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += people[i].first;
            res = max(res, dp[i]);
        }
        return res;
    }
};