#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> time(n);
        for (int j = 0; j < m; j++) {
            ll curTime = 0;
            for (int i = 0; i < n; i++) {
                curTime = max(curTime, time[i]) + skill[i] * mana[j];
            }
            time[n - 1] = curTime;
            for (int i = n - 2; i >= 0; i--) {
                time[i] = time[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return time[n - 1];
    }
};