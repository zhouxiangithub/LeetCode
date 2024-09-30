#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    using ll = long long;
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<ll> points(n);
        for (int i = 0; i < n; i++) {
            points[edges[i]] += i;
        }
        ll ma = INT_MIN;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (points[i] > ma) {
                ma = points[i];
                res = i;
            }
        }
        return res;
    }
};