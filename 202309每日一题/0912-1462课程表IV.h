#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<int>& visited, vector<vector<bool>>& isPre, int u)
    {
        if (visited[u])
        {
            return;
        }
        visited[u] = 1;
        for (auto& v : edges[u])
        {
            dfs(edges, visited, isPre, v);
            isPre[u][v] = true;
            for (int i = 0; i < isPre.size(); i++)
            {
                isPre[u][i] = isPre[u][i] | isPre[v][i]; //间接的(传递性)
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto& pre : prerequisites)
        {
            edges[pre[0]].push_back(pre[1]);
        }
        
        for (int i = 0; i < numCourses; i++)
        {
            dfs(edges, visited, isPre, i);
        }

        for (auto& query : queries)
        {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto& pre : prerequisites)
        {
            edges[pre[0]].push_back(pre[1]);
            indeg[pre[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (auto& v : edges[u])
            {
                isPre[u][v] = true;
                for (int i = 0; i < numCourses; i++)
                {
                    isPre[i][v] = isPre[i][v] | isPre[i][u]; //间接的(传递性)
                }
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        for (auto& query : queries)
        {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};