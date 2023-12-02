#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int> ans(INT_MAX / 2, -1);
        vector<vector<int>> mp(n, vector<int>(n, INT_MAX / 2));
        for (auto& edge : edges)
        {
            int from = edge[0], to = edge[1], weight = edge[2];
            mp[from][to] = mp[to][from] = weight;
        }
        for (int k = 0; k < n; k++)
        {
            mp[k][k] = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (mp[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= ans.first)
            {
                ans = { cnt,i };
            }
        }
        return ans.second;
    }
};