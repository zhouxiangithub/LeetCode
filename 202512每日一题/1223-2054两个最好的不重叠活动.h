#pragma once
using namespace std;
#include <vector>
#include <algorithm>

struct Event
{
    int timestamp;
    int option; // 0×ó±ß½ç,1ÓÒ±ß½ç
    int value;
    Event(int _timestamp, int _option, int _value) :timestamp(_timestamp), option(_option), value(_value) {}
    bool operator<(const Event& that) const {
        return tie(timestamp, option) < tie(that.timestamp, that.option);
    }
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Event> evs;
        for (const auto& event : events) {
            evs.emplace_back(event[0], 0, event[2]);
            evs.emplace_back(event[1], 1, event[2]);
        }
        sort(evs.begin(), evs.end());

        int res = 0, bestFirst = 0;
        for (const auto& [timestamp, option, value] : evs) {
            if (option == 0) {
                res = max(res, value + bestFirst);
            }
            else {
                bestFirst = max(bestFirst, value);
            }
        }
        return res;
    }
};