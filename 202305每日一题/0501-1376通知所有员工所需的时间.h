#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            map[manager[i]].emplace_back(i);
        }
        function<int(int)> dfs = [&](int cur)->int {
            int res = 0;
            //遍历当前节点的所有子节点,计算从子节点到当前节点的时间
            for (int neighbor : map[cur])
            {
                res = max(res, dfs(neighbor));
            }
            //加上当前节点到其上级节点的时间
            return informTime[cur] + res;
        };
        return dfs(headID);
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            map[manager[i]].emplace_back(i);
        }
        queue<pair<int, int>> q; //(node,time)
        q.emplace(headID, 0);
        int res = 0;
        while (!q.empty())
        {
            auto [node, time] = q.front();
            q.pop();
            if (!map.count(node))
            {
                //如果这个员工没有管理其他员工
                res = max(res, time);
            }
            else
            {
                //如果这个员工管理其他员工,将直接报告给他的员工加入到队列中
                for (int neighbor : map[node])
                {
                    q.emplace(neighbor, time + informTime[node]);
                }
            }
        }
        return res;
    }
};