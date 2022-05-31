#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    /*
        A(x1,y1) B(x2,y2) C(x3,y3)
        AB=(x2-x1,y2-y1) AC=(x3-x1,y3-y1)
        ²æ³Ë£ºS=0.5*AB*AC=0.5*[(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)]
    */
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        return 0.5 * abs(x2 * y3 + x1 * y2 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0.0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    res = max(res, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }
        return res;
    }
};