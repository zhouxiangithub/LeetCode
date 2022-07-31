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
    ���ڸ���������[start,end)������ÿ�β��������ڵ���end�ĵ�һ������[l1,r1)��
    ͬʱ������[l1,r1)��ǰһ������Ϊ[l2,r2)����ʱ�������r2<=start<end<=l1������������Ԥ����
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