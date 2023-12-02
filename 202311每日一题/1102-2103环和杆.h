#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    static constexpr int POLE_NUM = 10;
    int countPoints(string rings) {
        vector<int> state(POLE_NUM);
        int n = rings.size();
        for (int i = 0; i < n; i += 2)
        {
            char color = rings[i];
            int index = rings[i + 1] - '0';
            if (color == 'R')
            {
                state[index] |= 1;
            }
            else if (color == 'G')
            {
                state[index] |= 2;
            }
            else
            {
                state[index] |= 4;
            }
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++)
        {
            res += (state[i] == 7);
        }
        return res;
    }
};