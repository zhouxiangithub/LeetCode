#pragma once
using namespace std;
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //�����з������ı�Ŷ����뵽һ�����򼯺ϵ���
        set<int> available;
        for (int i = 0; i < k; i++)
        {
            available.insert(i);
        }

        //�����ڴ�������ķ������Ĵ������ʱ��ͱ�Ŷ����뵽һ�����ȶ��е��У����ȶ���������׵ķ������Ĵ������ʱ����С
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy; //С����
        
        //��һ�������¼��Ӧ�����������������Ŀ
        vector<int> requests(k);
        
        for (int i = 0; i < arrival.size(); i++)
        {
            /*
                ���赱ǰ���������Ϊ��i��
                ���busy��Ϊ�գ���ô�����ж�busy�Ķ��׶�Ӧ�ķ������Ľ���ʱ���Ƿ�С�ڵ��ڵ�ǰ���󵽴��ʱ��arrival[i]
                ����ǣ���ô���ǽ�����busy���Ƴ������ҽ��÷������ı�ŷ���available���У�Ȼ���ٴν����ж�
            */
            while (!busy.empty() && busy.top().first <= arrival[i])
            {
                available.insert(busy.top().second);
                busy.pop();
            }

            //���availableΪ�գ���ô�����󱻶���
            if (available.empty())
            {
                continue;
            }

            /*
                �������available�д��ڵ���(i mod k)�ĵ�һ��Ԫ��
                ������ҳɹ�����ô������Ϊ��������ķ�����������available�б����С�ķ�������Ϊ��������ķ�����
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