#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000000); //dp[i]表示放下前i本书所用的最小高度
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int maxHeight = 0, curWidth = 0;
            for (int j = i; j >= 0; j--)
            {
                curWidth += books[j][0];
                if (curWidth > shelfWidth)
                {
                    break;
                }
                maxHeight = max(maxHeight, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);
            }
        }
        return dp[n];
    }
};