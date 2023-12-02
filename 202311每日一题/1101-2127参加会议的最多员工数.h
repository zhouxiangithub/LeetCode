#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        //ͳ�����
        vector<int> indeg(n);
        for (int i = 0; i < n; i++)
        {
            indeg[favorite[i]]++;
        }
        vector<int> used(n), f(n, 1); //f[i]��ʾ���ڵ�iΪֹ�������·�������Ľڵ����
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!indeg[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            used[u] = true;
            q.pop();
            int v = favorite[u];
            f[v] = max(f[v], f[u] + 1);
            indeg[v]--;
            if (!indeg[v])
            {
                q.push(v);
            }
        }

        int ring = 0, total = 0;
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                int j = favorite[i];
                if (favorite[j] == i) //���Ĵ�СΪ2
                {
                    total += f[i] + f[j];
                    used[i] = used[j] = true;
                }
                else //���Ĵ�С����Ϊ3
                {
                    int u = i, cnt = 0;
                    while (true)
                    {
                        cnt++;
                        u = favorite[u];
                        used[u] = true;
                        if (u == i)
                        {
                            break;
                        }
                    }
                    ring = max(ring, cnt);
                }
            }
        }

        return max(ring, total);
    }
};