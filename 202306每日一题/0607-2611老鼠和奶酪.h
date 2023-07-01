#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0;
        int n = reward1.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            ans += reward2[i];
            diffs[i] = reward1[i] - reward2[i];
        }
        sort(diffs.begin(), diffs.end());
        for (int i = 1; i <= k; i++)
        {
            ans += diffs[n - i];
        }
        return ans;
    }
};

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0;
        int n = reward1.size();
        priority_queue<int, vector<int>, greater<int>> pq; //greater sort从大到小,top出数据从小到大
        for (int i = 0; i < n; i++)
        {
            ans += reward2[i];
            pq.emplace(reward1[i] - reward2[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};