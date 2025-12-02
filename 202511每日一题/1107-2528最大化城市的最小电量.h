#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](long long val) -> bool {
            vector<long long> diff = cnt;
            long long sum = 0;
            long long remain = k;

            for (int i = 0; i < n; i++) {
                sum += diff[i];
                if (sum < val) {
                    long long add = val - sum;
                    if (remain < add) {
                        return false;
                    }
                    remain -= add;
                    int end = min(n, i + r + r + 1); // 越往后加越好,选择在 i+r 处增加供电站
                    diff[end] -= add;
                    sum += add;
                }
            }
            return true;
        };

        long long res = 0;
        long long low = *min_element(stations.begin(), stations.end());
        long long high = accumulate(stations.begin(), stations.end(), 0LL) + k;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                res = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }
};