#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int idx = 0;
        int cap = 0;
        for (int bus : buses) {
            cap = capacity;
            while (cap > 0 && idx < passengers.size() && passengers[idx] <= bus) {
                cap--;
                idx++;
            }
        }
        idx--;
        int last = cap > 0 ? buses.back() : passengers[idx];
        while (idx >= 0 && passengers[idx] == last) {
            idx--;
            last--;
        }
        return last;
    }
};