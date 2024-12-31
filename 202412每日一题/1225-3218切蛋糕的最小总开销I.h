#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        
        int ans = 0;
        int row = 1, col = 1;
        int i = 0, j = 0;
        for (int len = 0; len < m + n - 2; len++) {
            bool isHorizontal = false;
            int cost = 0;
            if (i < m - 1 && j < n - 1) {
                isHorizontal = horizontalCut[i] > verticalCut[j];
                cost = isHorizontal ? horizontalCut[i++] : verticalCut[j++];
            }
            else if (i < m - 1) {
                isHorizontal = true;
                cost = horizontalCut[i++];
            }
            else {
                cost = verticalCut[j++];
            }
            
            if (isHorizontal) {
                ans += cost * col;
                row++;
            }
            else {
                ans += cost * row;
                col++;
            }
        }

        return ans;
    }
};