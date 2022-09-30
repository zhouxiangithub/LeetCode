#pragma once
using namespace std;
#include <unordered_set>
#include <numeric>

/*
    编号6k+1，受按钮1、3、4影响
    编号6k+2,6k+6，受按钮1、2影响
    编号6k+3,6k+5，受按钮1、3影响
    编号6k+4，受按钮1、2、4影响
    因此，只需要考虑四个灯泡，即可知道所有灯泡的最后状态。
*/
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        for (int i = 0; i < (1 << 4); i++)
        {
            vector<int> pressArr(4); //表示4个按钮的按动情况
            for (int j = 0; j < 4; j++)
            {
                pressArr[j] = (i >> j) & 1;
            }
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);
            if (sum % 2 == presses % 2 && sum <= presses)
            {
                int status = pressArr[0] ^ pressArr[2] ^ pressArr[3];
                if (n >= 2)
                {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3)
                {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4)
                {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return seen.size();
    }
};