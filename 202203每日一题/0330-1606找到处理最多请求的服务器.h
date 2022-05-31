#pragma once
using namespace std;
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //将空闲服务器的编号都放入到一个有序集合当中
        set<int> available;
        for (int i = 0; i < k; i++)
        {
            available.insert(i);
        }

        //将正在处理请求的服务器的处理结束时间和编号都放入到一个优先队列当中，优先队列满足队首的服务器的处理结束时间最小
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy; //小顶堆
        
        //用一个数组记录对应服务器处理的请求数目
        vector<int> requests(k);
        
        for (int i = 0; i < arrival.size(); i++)
        {
            /*
                假设当前到达的请求为第i个
                如果busy不为空，那么我们判断busy的队首对应的服务器的结束时间是否小于等于当前请求到达的时间arrival[i]
                如果是，那么我们将它从busy中移除，并且将该服务器的编号放入available当中，然后再次进行判断
            */
            while (!busy.empty() && busy.top().first <= arrival[i])
            {
                available.insert(busy.top().second);
                busy.pop();
            }

            //如果available为空，那么该请求被丢弃
            if (available.empty())
            {
                continue;
            }

            /*
                否则查找available中大于等于(i mod k)的第一个元素
                如果查找成功，那么将它作为处理请求的服务器；否则将available中编号最小的服务器作为处理请求的服务器
            */ 
            auto p = available.lower_bound(i % k);
            if (p == available.end())
            {
                p = available.begin();
            }

            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }

        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            if (requests[i] == maxRequest)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};