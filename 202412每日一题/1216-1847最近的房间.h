#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <set>

struct Event {
    // �¼������ͣ�0 ��ʾ���䣬1 ��ʾѯ��
    int type;

    // ����� size ����ѯ�ʵ� minSize
    int size;
    
    // ����� roomId ����ѯ�ʵ� preferred
    int id;
    
    // ���������� room �е�ԭʼ��Ż���ѯ�������� queries �е�ԭʼ���
    int origin;

    Event(int _type, int _size, int _id, int _origin) : type(_type), size(_size), id(_id), origin(_origin) {}

    // �Զ���ȽϺ����������¼��� size ��������
    // ��� size ��ͬ�����ȿ��Ƿ���
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
        set<int> valid; // �洢���� roomId �����򼯺�
        for (const auto& event : events) {
            if (event.type == 0) { // room event
                valid.insert(event.id);
            }
            else { // query event
                int dist = INT_MAX;
                auto it = valid.lower_bound(event.id); // >= ���ڵ���Сֵ
                if (it != valid.end() && (*it - event.id < dist)) {
                    dist = *it - event.id;
                    ans[event.origin] = *it;
                }
                if (it != valid.begin()) {
                    it = prev(it); // С�ڵ����ֵ
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