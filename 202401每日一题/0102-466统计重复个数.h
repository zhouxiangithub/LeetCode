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
            //多遍历一个s1看能否找到循环节
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

            //还没有找到循环节所有的s1就用完了
            if (s1cnt == n1)
            {
                return s2cnt / n2;
            }

            //出现了之前的index表示找到了循环节
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

        //S1包含s2的数量
        int ans = pre_loop.second + ((n1 - pre_loop.first) / in_loop.first) * in_loop.second;

        //S1的末尾还剩下一些s1
        int s1_remain = (n1 - pre_loop.first) % in_loop.first;

        //剩余匹配
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

        //S1包含ans个s2 <==> S1包含ans/n2个S2
        return ans / n2;
    }
};