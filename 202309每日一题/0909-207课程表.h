#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool flag = true;

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
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        return flag;
    }
};

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int visited = 0;
        while (!q.empty())
        {
            visited++;
            int u = q.front();
            q.pop();
            for (int v : edges[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};