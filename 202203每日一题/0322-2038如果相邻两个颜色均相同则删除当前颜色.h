#pragma once
using namespace std;
#include <string>

/*
    当colors中有一串连续的长度为LA的A时，Alice可以删除中间的LA-2个A
    对比Alice和Bob的可操作数即可
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int freq[2] = { 0, 0 };
        char cur = 'C';
        int cnt = 0;
        for (char c : colors)
        {
            if (c != cur)
            {
                cur = c;
                cnt = 1;
            }
            else
            {
                cnt += 1;
                if (cnt >= 3)
                {
                    freq[cur - 'A'] += 1;
                }
            }
        }
        return freq[0] > freq[1];
    }

    bool winnerOfGame1(string colors) {
        int cnt = 0, n = colors.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
            {
                cnt += colors[i] == 'A' ? 1 : -1;
            }
        }
        return cnt > 0;
    }
};