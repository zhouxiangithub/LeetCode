#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int left = candidates - 1, right = n - candidates;
        if (left + 1 < right) {
            for (int i = 0; i <= left; i++) {
                q.emplace(costs[i], i);
            }
            for (int j = right; j <= n - 1; j++) {
                q.emplace(costs[j], j);
            }
        }
        else
        {
            for (int i = 0; i < n; i++) {
                q.emplace(costs[i], i);
            }
        }
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            auto [cost, id] = q.top();
            q.pop();
            ans += cost;
            if (left + 1 < right) {
                if (id <= left) {
                    left++;
                    q.emplace(costs[left], left);
                }
                else
                {
                    right--;
                    q.emplace(costs[right], right);
                }
            }
        }
        return ans;
    }
};