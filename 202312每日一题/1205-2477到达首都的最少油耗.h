#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> g(n + 1);
        for (auto& road : roads)
        {
            g[road[0]].push_back(road[1]);
            g[road[1]].push_back(road[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int cur, int bf)->int {
            int peopleSum = 1;
            for (auto nx : g[cur])
            {
                if (nx != bf)
                {
                    int peopleCnt = dfs(nx, cur);
                    peopleSum += peopleCnt;
                    res += (peopleCnt + seats - 1) / seats;
                }
            }
            return peopleSum;
        };
        dfs(0, -1);
        return res;
    }
};