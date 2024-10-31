#pragma once
using namespace std;
#include <vector>

/*
    前 n-1 段花费的时间为 t
    t + dist[n-1]/v <= hour
    t*v + dist[n-1] <= hour*v
*/
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long hr = llround(hour * 100);
        if (hr <= (n - 1) * 100) {
            return -1;
        }

        int left = 1, right = 1e7;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long t = 0;
            for (int i = 0; i < n - 1; i++) {
                t += (dist[i] - 1) / mid + 1;
            }
            t *= mid;
            t += dist[n - 1];
            if (t * 100 <= hr * mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};