#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = n;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                cnt++;
                if (i == n - 1) {
                    res += (long long)cnt * (cnt + 1) / 2;
                }
            }
            else {
                res += (long long)cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        return res;
    }
};

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            res += cnt;
        }
        return res;
    }
};