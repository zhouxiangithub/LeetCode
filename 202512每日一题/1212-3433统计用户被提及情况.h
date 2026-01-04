#pragma once
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> res(numberOfUsers);
        vector<int> nextOnlineTime(numberOfUsers);

        sort(events.begin(), events.end(), [&](const vector<string>& s1, const vector<string>& s2) {
            int s1Timestamp = stoi(s1[1]);
            int s2Timestamp = stoi(s2[1]);
            if (s1Timestamp != s2Timestamp) {
                return s1Timestamp < s2Timestamp;
            }
            if (s2[0] == "OFFLINE") {
                return false;
            }
            return true;
        });

        for (auto&& event : events) {
            int curTimestamp = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") { // 所有用户
                    for (int i = 0; i < numberOfUsers; i++) {
                        res[i]++;
                    }
                }
                else if (event[2] == "HERE") { // 所有在线用户
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnlineTime[i] <= curTimestamp) {
                            res[i]++;
                        }
                    }
                }
                else { // 具体用户
                    int size = event[2].size();
                    int userId = 0;
                    for (int i = 0; i < size; i++) {
                        if (isdigit(event[2][i])) {
                            userId = userId * 10 + (event[2][i] - '0');
                        }
                        if (i == size - 1 || event[2][i + 1] == ' ') {
                            res[userId]++;
                            userId = 0;
                        }
                    }
                }
            }
            else { // OFFLINE
                int userId = stoi(event[2]);
                nextOnlineTime[userId] = curTimestamp + 60;
            }
        }

        return res;
    }
};