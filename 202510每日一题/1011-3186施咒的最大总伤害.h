#pragma once
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> valToCnt; // val 值已经排好序了
        for (int val : power) {
            valToCnt[val]++;
        }

        vector<pair<int, int>> vec = { };
        for (auto& pair : valToCnt) {
            vec.push_back(pair);
        }

        int n = vec.size();
        vector<long long> f(n, 0);
        long long mx = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < i && vec[j].first < vec[i].first - 2) { // val 值已经排好序了
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL * vec[i].first * vec[i].second;
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f[i]);
        }
        return res;
    }
};