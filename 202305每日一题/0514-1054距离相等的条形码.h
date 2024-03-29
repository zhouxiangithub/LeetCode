#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int b : barcodes)
        {
            count[b]++;
        }
        priority_queue<pair<int, int>> q; //(剩余数量,元素值)
        for (const auto& [x, cx] : count)
        {
            q.push({ cx,x });
        }
        vector<int> res;
        while (q.size())
        {
            auto [cx, x] = q.top();
            q.pop();
            if (res.empty() || res.back() != x)
            {
                res.push_back(x);
                if (cx > 1)
                {
                    q.push({ cx - 1,x });
                }
            }
            else
            {
                if (q.size() < 1)
                {
                    return res;
                }
                auto [cy, y] = q.top(); //选出第二多的元素
                q.pop();
                res.push_back(y);
                if (cy > 1)
                {
                    q.push({ cy - 1,y });
                }
                q.push({ cx,x });
            }
        }
        return res;
    }
};