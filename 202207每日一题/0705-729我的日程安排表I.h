#pragma once
using namespace std;
#include <vector>
#include <set>

class MyCalendar {
    vector<pair<int, int>> booked;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto& [l, r] : booked)
        {
            if (l < end && start < r)
            {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/*
    对于给定的区间[start,end)，我们每次查找起点大于等于end的第一个区间[l1,r1)，
    同时紧挨着[l1,r1)的前一个区间为[l2,r2)，此时如果满足r2<=start<end<=l1，则该区间可以预订。
*/
class MyCalendar {
    set<pair<int, int>> booked;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = booked.lower_bound({ end,0 });
        if (it == booked.begin() || (--it)->second <= start)
        {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};