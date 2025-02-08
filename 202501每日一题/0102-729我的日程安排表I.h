#pragma once
using namespace std;
#include <vector>

class MyCalendar {
    vector<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        for (auto& [l, r] : booked) {
            if (start<r && end>l) {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};