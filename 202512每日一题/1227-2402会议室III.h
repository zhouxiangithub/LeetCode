#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& m1, const vector<int>& m2)->bool {
            return m1[0] < m2[0];
            });

        priority_queue<int, vector<int>, greater<int>> availRooms;
        for (int i = 0; i < n; i++) {
            availRooms.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> usedRooms;
        vector<int> usedCount(n);
        
        long long curTime = 0;
        for (const auto& meeting : meetings) {
            curTime = max(curTime, static_cast<long long>(meeting[0]));
            if (availRooms.empty()) {
                curTime = max(curTime, usedRooms.top().first);
            }
            while (!usedRooms.empty() && usedRooms.top().first <= curTime) {
                availRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }
            int room = availRooms.top();
            availRooms.pop();
            usedCount[room]++;
            usedRooms.push({ curTime + meeting[1] - meeting[0], room });
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (usedCount[i] > usedCount[res]) {
                res = i;
            }
        }
        return res;
    }
};