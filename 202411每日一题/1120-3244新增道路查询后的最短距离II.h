#pragma once
using namespace std;
#include <vector>
#include <numeric>

/**
* 新增附加条件: 任意两条单向道路要么是不相交的关系, 要么是包含的关系
* 
* 因此, 当新增一条单向通道时, 若已经被任一现有单向通道所包含, 则可忽略
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