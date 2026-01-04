#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid[0].size();
        int pos = n - 1;

        for (auto& row : grid) {
            int i;
            for (i = pos; i >= 0; i--) {
                if (row[i] >= 0) {
                    if (i < n - 1) {
                        pos = i + 1;
                        res += n - pos; // (n-1)-pos+1
                    }
                    break;
                }
            }
            if (i == -1) {
                res += n;
                pos = -1;
            }
        }

        return res;
    }
};