#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0, num = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 && x < m && y >= 0 && y < n)
                        {
                            sum += img[x][y];
                            num++;
                        }
                    }
                }
                ret[i][j] = sum / num;
            }
        }
        return ret;
    }
};