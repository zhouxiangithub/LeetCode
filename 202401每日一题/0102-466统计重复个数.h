#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
        {
            return 0;
        }

        int s1cnt = 0, s2cnt = 0, index = 0;

        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;

        while (true)
        {
            //�����һ��s1���ܷ��ҵ�ѭ����
            s1cnt++;

            for (char ch : s1)
            {
                if (ch == s2[index])
                {
                    index++;
                    if (index == s2.size())
                    {
                        s2cnt++;
                        index = 0;
                    }
                }
            }

            //��û���ҵ�ѭ�������е�s1��������
            if (s1cnt == n1)
            {
                return s2cnt / n2;
            }

            //������֮ǰ��index��ʾ�ҵ���ѭ����
            if (recall.count(index))
            {
                auto [s1cnt_, s2cnt_] = recall[index];
                pre_loop = { s1cnt_,s2cnt_ };
                in_loop = { s1cnt - s1cnt_,s2cnt - s2cnt_ };
                break;
            }
            else
            {
                recall[index] = { s1cnt,s2cnt };
            }
        }

        //S1����s2������
        int ans = pre_loop.second + ((n1 - pre_loop.first) / in_loop.first) * in_loop.second;

        //S1��ĩβ��ʣ��һЩs1
        int s1_remain = (n1 - pre_loop.first) % in_loop.first;

        //ʣ��ƥ��
        for (int i = 0; i < s1_remain; i++)
        {
            for (char ch : s1)
            {
                if (ch == s2[index])
                {
                    index++;
                    if (index == s2.size())
                    {
                        ans++;
                        index = 0;
                    }
                }
            }
        }

        //S1����ans��s2 <==> S1����ans/n2��S2
        return ans / n2;
    }
};