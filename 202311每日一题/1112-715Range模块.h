#pragma once
using namespace std;
#include <map>

class RangeModule {
private:
    map<int, int> intervals;

public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin())
        {
            auto start = prev(it);
            if (right <= start->second)
            {
                return;
            }
            if (left <= start->second)
            {
                left = start->first;
                intervals.erase(start);
            }
        }
        while (it != intervals.end() && right >= it->first)
        {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin())
        {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }

    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin())
        {
            auto start = prev(it);
            if (right <= start->second)
            {
                int r = start->second;
                if (left == start->first)
                {
                    intervals.erase(start);
                }
                else
                {
                    start->second = left;
                }
                if (right != r)
                {
                    intervals[right] = r;
                }
                return;
            }
            else if (left < start->second)
            {
                if (left == start->first)
                {
                    intervals.erase(start);
                }
                else
                {
                    start->second = left;
                }
            }
        }
        while (it != intervals.end() && right > it->first)
        {
            if (right >= it->second)
            {
                it = intervals.erase(it);
            }
            else
            {
                intervals[right] = it->second;
                intervals.erase(it);
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */