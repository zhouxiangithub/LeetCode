#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // �ж� t ʱ�����Ƿ������� totalTrips ����;
        auto check = [&](long long t)->bool {
            long long cnt = 0;
            for (int period : time) {
                cnt += t / period;
            }
            return cnt >= totalTrips;
        };

        long long left = 1;
        long long right = (long long)totalTrips * (*max_element(time.begin(), time.end()));
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};