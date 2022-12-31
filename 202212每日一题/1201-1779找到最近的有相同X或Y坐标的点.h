#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int best = numeric_limits<int>::max(), bestid = -1;
        for (int i = 0; i < n; i++)
        {
            int px = points[i][0], py = points[i][1];
            if (x == px)
            {
                int dist = abs(y - py);
                if (dist < best)
                {
                    best = dist;
                    bestid = i;
                }
            }
            else if (y == py)
            {
                int dist = abs(x - px);
                if (dist < best)
                {
                    best = dist;
                    bestid = i;
                }
            }
        }
        return bestid;
    }
};