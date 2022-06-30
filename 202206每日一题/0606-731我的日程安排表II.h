#pragma once
using namespace std;
#include <map>

class MyCalendarTwo {
private:
    map<int, int> cnt;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        int curBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto& [_, freq] : cnt)
        {
            curBook += freq;
            if (curBook > 2)
            {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */