#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> flag(n);
        for (int i = 0, leftSpace = 0, rightSpace = 0; i < n; i++) {
            if (leftSpace >= endTime[i] - startTime[i]) {
                flag[i] = 1;
            }
            leftSpace = max(leftSpace, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (rightSpace >= endTime[n - i - 1] - startTime[n - i - 1]) {
                flag[n - i - 1] = 1;
            }
            rightSpace = max(rightSpace, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = (i == 0 ? 0 : endTime[i - 1]);
            int right = (i == n - 1 ? eventTime : startTime[i + 1]);
            if (flag[i]) {
                res = max(res, right - left);
            }
            else {
                res = max(res, right - left - (endTime[i] - startTime[i]));
            }
        }
        return res;
    }
};