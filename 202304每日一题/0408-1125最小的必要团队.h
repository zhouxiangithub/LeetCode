#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; i++)
        {
            skill_index[req_skills[i]] = i;
        }
        vector<vector<int>> dp(1 << n); //满足技能集合为i的最小人数的数组
        for (int i = 0; i < m; i++)
        {
            int cur_kill = 0;
            for (string& s : people[i])
            {
                cur_kill |= 1 << skill_index[s];
            }
            for (int prev = 0; prev < dp.size(); prev++)
            {
                if (prev > 0 && dp[prev].empty())
                {
                    continue;
                }
                int comb = prev | cur_kill;
                if (comb == prev)
                {
                    continue;
                }
                if (dp[comb].empty() || dp[prev].size() + 1 < dp[comb].size())
                {
                    dp[comb] = dp[prev];
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};