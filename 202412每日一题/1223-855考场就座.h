#pragma once
using namespace std;
#include <set>
#include <queue>
#include <vector>

struct Comp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        int distance1 = p1.second - p1.first, distance2 = p2.second - p2.first;
        return distance1 / 2 < distance2 / 2 || (distance1 / 2 == distance2 / 2 && p1.first > p2.first);
    }
};

class ExamRoom {
private:
    int n;
    set<int> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

public:
    ExamRoom(int n) : n(n) {

    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int left = *seats.begin(), right = n - 1 - *seats.rbegin();
        while (seats.size() >= 2) {
            auto p = pq.top();
            if (seats.count(p.first) > 0 && seats.count(p.second) > 0 && *next(seats.find(p.first)) == p.second) {
                int distance = p.second - p.first;
                if (distance / 2 < right || distance / 2 < left - 1) { // 最左或最右的座位更优
                    break;
                }
                pq.pop();
                pq.push({ p.first, p.first + distance / 2 });
                pq.push({ p.first + distance / 2, p.second });
                seats.insert(p.first + distance / 2);
                return p.first + distance / 2;
            }
            pq.pop();
        }
        if (right > left) { // 最右的位置更优
            pq.push({ *seats.rbegin(), n - 1 });
            seats.insert(n - 1);
            return n - 1;
        }
        else {
            pq.push({ 0, *seats.begin() });
            seats.insert(0);
            return 0;
        }
    }

    void leave(int p) {
        if (p != *seats.begin() && p != *seats.rbegin()) {
            auto it = seats.find(p);
            pq.push({ *prev(it), *next(it) });
        }
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */