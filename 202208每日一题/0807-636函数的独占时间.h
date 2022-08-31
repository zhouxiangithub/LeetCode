#pragma once
using namespace std;
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st; //{idx,��ʼ���е�ʱ��}
        vector<int> res(n, 0);
        for (auto& log : logs)
        {
            char type[10];
            int idx, timestamp;
            //%[^:] ������ð����Ϊ��ͷ�ĵط�������ǰ�����Ϣ��Ϊһ���ַ�����ֵ����Ӧ�ı���
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's')
            {
                if (!st.empty())
                {
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
            }
            else
            {
                auto t = st.top();
                st.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!st.empty())
                {
                    st.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};