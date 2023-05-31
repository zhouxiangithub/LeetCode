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
            //������ǰ�ڵ�������ӽڵ�,������ӽڵ㵽��ǰ�ڵ��ʱ��
            for (int neighbor : map[cur])
            {
                res = max(res, dfs(neighbor));
            }
            //���ϵ�ǰ�ڵ㵽���ϼ��ڵ��ʱ��
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
                //������Ա��û�й�������Ա��
                res = max(res, time);
            }
            else
            {
                //������Ա����������Ա��,��ֱ�ӱ��������Ա�����뵽������
                for (int neighbor : map[node])
                {
                    q.emplace(neighbor, time + informTime[node]);
                }
            }
        }
        return res;
    }
};