#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        auto getTrend = [](int x, int y)->int {
            if (x == y) {
                return 0;
            }
            return x < y ? -1 : 1;
        };

        int n = temperatureA.size();
        int ans = 0, cur = 0;
        for (int i = 1; i < n; i++) {
            int tempA = getTrend(temperatureA[i - 1], temperatureA[i]);
            int tempB = getTrend(temperatureB[i - 1], temperatureB[i]);
            if (tempA == tempB) {
                cur++;
                ans = max(ans, cur);
            }
            else {
                cur = 0;
            }
        }
        return ans;
    }
};