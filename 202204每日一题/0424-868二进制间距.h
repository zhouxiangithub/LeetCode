#pragma once
using namespace std;
#include <algorithm>

/*
    从n二进制表示的低位开始进行遍历
*/
class Solution {
public:
    int binaryGap(int n) {
        int index = -1, ans = 0;
        for (int i = 0; n > 0; i++)
        {
            if (n & 1)
            {
                if (index != -1)
                {
                    ans = max(ans, i - index);
                }
                index = i;
            }
            n >>= 1;
        }
        return ans;
    }
};