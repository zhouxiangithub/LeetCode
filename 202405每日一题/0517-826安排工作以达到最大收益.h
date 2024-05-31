#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int res = 0, j = 0, maProfit = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int work : worker) {
            while (j < n && work >= jobs[j].first) {
                maProfit = max(maProfit, jobs[j].second);
                j++;
            }
            res += maProfit;
        }
        return res;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int res = 0, j = 0, maProfit = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(profit[i], difficulty[i]);
        }
        sort(jobs.begin(), jobs.end(), [](pair<int, int> j1, pair<int, int> j2) {
            return j1.first > j2.first || (j1.first == j2.first && j1.second > j2.second);
            });
        for (int work : worker) {
            int j = 0;
            while (j < n && work < jobs[j].second) {
                j++;
            }
            res += (j < n ? jobs[j].first : 0);
        }
        return res;
    }
};