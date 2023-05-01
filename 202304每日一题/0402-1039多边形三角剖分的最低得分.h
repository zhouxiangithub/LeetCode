#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> map;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j)->int {
            if (i + 2 > j)
            {
                return 0;
            }
            if (i + 2 == j)
            {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!map.count(key))
            {
                int minScore = INT_MIN;
                for (int k = i + 1; k < j; k++)
                {
                    minScore = min(minScore, values[i] * values[k] * values[j] + dp(i, k) + dp(k, j));
                }
                map[key] = minScore;
            }
            return map[key];
        };
        return dp(0, n - 1);
    }
};