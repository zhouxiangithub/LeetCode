#pragma once
using namespace std;
#include <map>

class MyCalendar {
private:
    map<int, int> cnt;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        int curBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto& [_, freq] : cnt)
        {
            curBook += freq;
            if (curBook > 1)
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */