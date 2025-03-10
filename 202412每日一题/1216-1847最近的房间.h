#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <set>

struct Event {
    // 事件的类型，0 表示房间，1 表示询问
    int type;

    // 房间的 size 或者询问的 minSize
    int size;
    
    // 房间的 roomId 或者询问的 preferred
    int id;
    
    // 房间在数组 room 中的原始编号或者询问在数组 queries 中的原始编号
    int origin;

    Event(int _type, int _size, int _id, int _origin) : type(_type), size(_size), id(_id), origin(_origin) {}

    // 自定义比较函数，按照事件的 size 降序排序
    // 如果 size 相同，优先考虑房间
    bool operator< (const Event& that) const {
        return size > that.size || (size == that.size && type < that.type);
    }
};

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = rooms.size(), n = queries.size();
        
        vector<Event> events;
        for (int i = 0; i < m; i++) {
            // room event
            events.emplace_back(0, rooms[i][1], rooms[i][0], i);
        }
        for (int i = 0; i < n; i++) {
            // query event
            events.emplace_back(1, queries[i][1], queries[i][0], i);
        }
        sort(events.begin(), events.end());

        vector<int> ans(n, -1);
        set<int> valid; // 存储房间 roomId 的有序集合
        for (const auto& event : events) {
            if (event.type == 0) { // room event
                valid.insert(event.id);
            }
            else { // query event
                int dist = INT_MAX;
                auto it = valid.lower_bound(event.id); // >= 大于的最小值
                if (it != valid.end() && (*it - event.id < dist)) {
                    dist = *it - event.id;
                    ans[event.origin] = *it;
                }
                if (it != valid.begin()) {
                    it = prev(it); // 小于的最大值
                    if (event.id - *it <= dist) {
                        dist = event.id - *it;
                        ans[event.origin] = *it;
                    }
                }
            }
        }
        return ans;
    }
};