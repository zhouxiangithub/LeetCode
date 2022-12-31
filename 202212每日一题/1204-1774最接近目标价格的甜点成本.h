#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    void dfs(const vector<int>& toppingCosts, int size, int curCost, int& res, const int target)
    {
        if (abs(res - target) < curCost - target)
        {
            return;
        }
        else if (abs(res - target) >= abs(curCost - target))
        {
            if (abs(res - target) > abs(curCost - target))
            {
                res = curCost;
            }
            else
            {
                res = min(res, curCost);
            }
        }
        if (size == toppingCosts.size())
        {
            return;
        }
        dfs(toppingCosts, size + 1, curCost + toppingCosts[size] * 2, res, target);
        dfs(toppingCosts, size + 1, curCost + toppingCosts[size], res, target);
        dfs(toppingCosts, size + 1, curCost, res, target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        for (auto& curCost : baseCosts)
        {
            dfs(toppingCosts, 0, curCost, res, target);
        }
        return res;
    }
};