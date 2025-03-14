#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    bool check(int dis, vector<int>& position, int m) {
        int pre = position[0], cnt = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - pre >= dis) {
                pre = position[i];
                cnt += 1;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0], ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, position, m)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};