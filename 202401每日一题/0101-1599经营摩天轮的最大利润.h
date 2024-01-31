#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1;

        int maxProfit = 0;
        int totalProfit = 0;

        int oper = 0;
        int customersCount = 0;
        int n = customers.size();

        int profitEachTime = 4 * boardingCost - runningCost;
        if (profitEachTime <= 0)
        {
            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            oper++;
            customersCount += customers[i];
            int curCustomers = min(customersCount, 4);
            customersCount -= curCustomers;
            totalProfit += curCustomers * boardingCost - runningCost;
            if (totalProfit > maxProfit)
            {
                maxProfit = totalProfit;
                ans = oper;
            }
        }
        if (customersCount == 0)
        {
            return ans;
        }

        if (customersCount > 0)
        {
            int times = customersCount / 4;
            
            totalProfit += times * profitEachTime;
            oper += times;
            if (totalProfit > maxProfit)
            {
                maxProfit = totalProfit;
                ans = oper;
            }

            int remain = customersCount % 4;
            totalProfit += remain * boardingCost - runningCost;
            oper++;
            if (totalProfit > maxProfit)
            {
                maxProfit = totalProfit;
                ans++;
            }
        }

        return ans;
    }
};