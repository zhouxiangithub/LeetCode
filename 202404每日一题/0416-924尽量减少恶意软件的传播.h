#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> ids(n); // ���ڵ����,�ڵ�������ͨ�����ı��
        unordered_map<int, int> id_to_size; // ÿ���ڵ���Ĵ�С,������ͨ�����нڵ������
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (!ids[i]) {
                ids[i] = ++id;
                int size = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v = 0; v < n; v++) {
                        if (!ids[v] && graph[u][v] == 1) {
                            size++;
                            q.push(v);
                            ids[v] = id;
                        }
                    }
                }
                id_to_size[id] = size;
            }
        }

        unordered_map<int, int> id_to_initials; // ÿ����ͨ������ʼʱ����Ⱦ�ڵ������
        for (int ini : initial) {
            id_to_initials[ids[ini]]++;
        }

        int ans = n + 1, ans_removed = 0;
        for (int ini : initial) {
            // ��ĳ����ͨ����ǡ��һ���ڵ㱻��Ⱦ,���Ƴ��ýڵ㼴�ɼ��ٸ���ͨ�����нڵ���������Ⱦ�ڵ�
            int removed = (id_to_initials[ids[ini]] == 1 ? id_to_size[ids[ini]] : 0);
            if (removed > ans_removed || (removed == ans_removed && ini < ans)) {
                ans = ini;
                ans_removed = removed;
            }
        }
        return ans;
    }
};