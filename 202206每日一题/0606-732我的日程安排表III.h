#pragma once
using namespace std;
#include <map>

class MyCalendarThree {
private:
    map<int, int> cnt;
public:
    MyCalendarThree() {

    }

    //³¬Ê±
    int book(int start, int end) {
        int ans = 0;
        for (int i = start; i < end; i++)
        {
            cnt[i]++;
        }
        for (auto& [_, freq] : cnt)
        {
            ans = max(freq, ans);
        }
        return ans;
    }

    //²åÆì·¨
    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto& [_, freq] : cnt)
        {
            maxBook += freq;
            ans = max(maxBook, ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */