#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        //����ȴ��еĹ������ȼ��ȽϹ���:ʱ���ܺ�Խ��,Ч��Խ��,���ȼ�Խ��,Խ���ȱ�ȡ��
        auto wait_priority_cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];
            int time_y = time[y][0] + time[y][2];
            return time_x != time_y ? time_x < time_y : x < y;
        };

        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp), wait_right(wait_priority_cmp);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work_left, work_right;

        int remain = n, cur_time = 0;
        for (int i = 0; i < k; i++)
        {
            wait_left.push(i);
        }

        while (remain > 0 || !work_right.empty() || !wait_right.empty())
        {
            //��work_left��work_right�еĹ�����ɹ���,������ȡ��,���ֱ���õ�wait_left��wait_right��
            while (!work_left.empty() && work_left.top().first <= cur_time)
            {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top().first <= cur_time)
            {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            if (!wait_right.empty())
            {
                //���Ҳ��й����ڵȴ�,��ȡ�����ȼ���͵Ĺ��˲�����
                int id = wait_right.top();
                wait_right.pop();
                cur_time += time[id][2];
                work_left.push({ cur_time + time[id][3],id });
            }
            else if (remain > 0 && !wait_left.empty())
            {
                //���Ҳ໹������,��������й����ڵȴ�,��ȡ�����ȼ���͵Ĺ��˲�����
                int id = wait_left.top();
                wait_left.pop();
                cur_time += time[id][0];
                work_right.push({ cur_time + time[id][1],id });
                remain--;
            }
            else
            {
                //����,û������Ҫ����,ʱ����ɵ�work_left��work_right�е��������ʱ��
                int next_time = INT_MAX;
                if (!work_left.empty())
                {
                    next_time = min(next_time, work_left.top().first);
                }
                if (!work_right.empty())
                {
                    next_time = min(next_time, work_right.top().first);
                }
                if (next_time != INT_MAX)
                {
                    cur_time = max(cur_time, next_time);
                }
            }
        }

        return cur_time;
    }
};