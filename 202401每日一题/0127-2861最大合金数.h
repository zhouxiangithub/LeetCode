#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int left = 1, right = budget + *max_element(stock.begin(), stock.end()), ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            bool flag = false;
            for (int i = 0; i < k; i++)
            {
                long long spend = 0;
                for (int j = 0; j < n; j++)
                {
                    spend += max(static_cast<long long>(composition[i][j]) * mid - stock[j], 0LL) * cost[j];
                }
                if (spend <= budget)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};