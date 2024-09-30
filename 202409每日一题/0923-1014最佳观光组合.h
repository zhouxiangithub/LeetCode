#pragma once
using namespace std;
#include <vector>

/*
    最大化 values[i]+i+values[j]−j 的值
    在 [0,j−1] 中 values[i]+i 的最大值 mx, 景点 j 的答案即为 mx+values[j]−j 
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};