#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
        });

        priority_queue<int> q;
        int total = 0; //���������пγ̵���ʱ��

        for (const auto& course : courses)
        {
            int durationi = course[0], lastDayi = course[1];
            if (total + durationi <= lastDayi)
            {
                total += durationi;
                q.push(durationi);
            }
            else if (!q.empty() && q.top() > durationi)
            {
                //��ʱ��������ſγ�ȡ��������ǰ�γ̷���
                total -= (q.top() - durationi);
                q.pop();
                q.push(durationi);
            }
        }

        return q.size();
    }
};