#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int m = points.size(), n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int qx = queries[i][0], qy = queries[i][1], qr = queries[i][2];
            for (int j = 0; j < m; j++)
            {
                int px = points[j][0], py = points[j][1];
                if ((qx - px) * (qx - px) + (qy - py) * (qy - py) <= qr * qr)
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};