#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int res = 0;
        vector<vector<int>> prev(n + 1);
        for (auto& relation : relations)
        {
            prev[relation[1]].emplace_back(relation[0]);
        }

        unordered_map<int, int> mp;
        function<int(int)> dp = [&](int i)->int {
            if (!mp.count(i))
            {
                int cur = 0;
                for (int j : prev[i])
                {
                    cur = max(cur, dp(j));
                }
                cur += time[i - 1];
                mp[i] = cur;
            }
            return mp[i];
        };

        for (int i = 1; i <= n; i++)
        {
            res = max(res, dp(i));
        }
        return res;
    }
};