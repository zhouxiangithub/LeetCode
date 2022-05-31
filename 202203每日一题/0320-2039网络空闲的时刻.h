#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
    ���ù��������������ڵ�0�������ڵ����̾��롣
    Ȼ���������ÿ���ڵ��Ϊ���е�ʱ�䣬�����нڵ㶼��Ϊ����ʱ���������缴��Ϊ����״̬��
    ���������������ʱ�伴Ϊ�����ڵ�������Ŀ���ʱ�䡣

    �ڵ�vÿ����һ����Ϣ�󣬾���2*dist[v]�������յ��ظ�
    
    ��2*dist[v]<=patience[v]ʱ���ڵ�v��Ϊ���е�ʱ��Ϊ��2*dist[v]+1
    ��2*dist[v]>patience[v]ʱ��
        ���ٷ��� (2*dist[v]-1) / patience[v] ����Ϣ
        ���һ�η�����Ϣ��ʱ��Ϊ��patience[v] * {(2*dist[v]-1) / patience[v]}
        ���һ���յ��ظ���ʱ��Ϊ��patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v]
        �ڵ�v��Ϊ���е�ʱ��Ϊ��patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v] + 1
    
    ���ϣ�
        �ڵ�v��Ϊ���е�ʱ��Ϊ��patience[v] * {(2*dist[v]-1) / patience[v]} + 2*dist[v] + 1
*/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n); //��¼ÿ���ڵ���ڵ������ڵ�
        vector<bool> visit(n, false);
        for (auto& v : edges)
        {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty())
        {
            int sz = qu.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = qu.front();
                qu.pop();
                for (auto& v : adj[curr])
                {
                    if (visit[v])
                    {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};