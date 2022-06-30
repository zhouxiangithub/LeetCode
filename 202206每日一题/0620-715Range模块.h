#pragma once
using namespace std;
#include <map>
#include <algorithm>

class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left); //�ҳ���һ������left<lj������
        if (it != intervals.begin())
        {
            auto start = prev(it); //�ҳ����һ������li<=left������
            if (right <= start->second) // li <= left < right <= ri
            {
                return;
            }
            if (left <= start->second) // li <= left <= ri < right
            {
                left = start->first;
                intervals.erase(start);
            }
        }
        //�������
        while (it != intervals.end() && right >= it->first) // right >= lj
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
            if (right <= start->second) // li <= left < right <= ri
            {
                int ri = start->second;
                if (left == start->first)
                {
                    intervals.erase(start);
                }
                else
                {
                    start->second = left;
                }
                if (right != ri)
                {
                    intervals[right] = ri;
                }
                return;
            }
            else if (left < start->second) // li <= left < ri < right
            {
                start->second = left;
            }
        }
        //�������
        while (it != intervals.end() && right > it->first) // right > lj
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

private:
    map<int, int> intervals;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */