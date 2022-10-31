#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool dfs(int curnode, int nowcolor, vector<int>& color, const vector<vector<int>>& g)
    {
        color[curnode] = nowcolor;
        for (auto& nextnode : g[curnode])
        {
            if (color[nextnode] && color[nextnode] == color[curnode])
            {
                return false;
            }
            // 3(11) ^ nowcolor 异或进行染色分组, 0表示未分组, 1表示分组1, 2表示分组2
            // 3(11) ^ 1(01) = 2(10), 3(11) ^ 2(10) = 1(01) 
            if (!color[nextnode] && !dfs(nextnode, 3 ^ nowcolor, color, g))
            {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes)
        {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0 && !dfs(i, 1, color, g))
            {
                return false;
            }
        }
        return true;
    }
};