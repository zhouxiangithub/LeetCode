#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool flag = true;
    vector<int> result;

public:
    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!flag)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                flag = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && flag; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        if (!flag)
        {
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
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
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v : edges[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses)
        {
            return {};
        }
        return result;
    }
};