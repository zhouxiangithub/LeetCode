#pragma once
using namespace std;
#include <queue>

class RecentCounter {
    queue<int> que;
public:
    RecentCounter() {

    }

    int ping(int t) {
        que.push(t);
        while (t - que.front() > 3000)
        {
            que.pop();
        }
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter {
    int arr[10000];
    int left = 0, right = 0;
public:
    RecentCounter() {

    }

    int ping(int t) {
        arr[right++] = t;
        while (t - arr[left] > 3000)
        {
            left++;
        }
        return right - left;
    }
};