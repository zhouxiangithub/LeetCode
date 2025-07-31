#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int left = 1, right = 0;
        for (auto meeting : meetings) {
            if (right < meeting[0]) {
                days -= (right - left + 1);
                left = meeting[0];
            }
            right = max(right, meeting[1]);
        }
        days -= (right - left + 1);
        return days;
    }
};