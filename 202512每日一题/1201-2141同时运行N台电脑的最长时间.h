#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n, res = 0;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long sum = 0;
            for (int battery : batteries) {
                sum += min(static_cast<long long>(battery), mid);
            }
            if (sum >= n * mid) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};