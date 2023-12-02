#pragma once
using namespace std;
#include <vector>
#include <queue>

//����ÿ����ͨ����,���С��1������Ҫ�����Ĵ���
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tol = n / 2;
        vector<vector<int>> graph(tol);
        for (int i = 0; i < n; i += 2)
        {
            int j = row[i] / 2;
            int k = row[i + 1] / 2;
            if (j != k)
            {
                graph[j].push_back(k);
                graph[k].push_back(j);
            }
        }
        vector<int> visited(tol, 0);
        int res = 0;
        for (int i = 0; i < tol; i++)
        {
            if (visited[i] == 0)
            {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                int cnt = 0;

                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    cnt += 1;
                    for (int y : graph[x])
                    {
                        if (visited[y] == 0)
                        {
                            visited[y] = 1;
                            q.push(y);
                        }
                    }
                }

                res += cnt - 1;
            }
        }
        return res;
    }
};