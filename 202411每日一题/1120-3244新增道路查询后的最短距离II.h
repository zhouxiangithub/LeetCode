#pragma once
using namespace std;
#include <vector>
#include <numeric>

/**
* ������������: �������������·Ҫô�ǲ��ཻ�Ĺ�ϵ, Ҫô�ǰ����Ĺ�ϵ
* 
* ���, ������һ������ͨ��ʱ, ���Ѿ�����һ���е���ͨ��������, ��ɺ���
*/
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> roads(n); // roads[u]=v <==> u->v
        iota(roads.begin(), roads.end(), 1);
        vector<int> res;
        int dist = n - 1;
        for (auto& query : queries) {
            int k = roads[query[0]];
            roads[query[0]] = query[1];
            while (k != -1 && k < query[1]) {
                int t = roads[k];
                roads[k] = -1;
                k = t;
                dist--;
            }
            res.push_back(dist);
        }
        return res;
    }
};