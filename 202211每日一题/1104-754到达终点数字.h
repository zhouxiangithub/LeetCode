#pragma once
using namespace std;
#include <algorithm>

/*
    sum = 1+2+...+n > target, d = sum - target
    1.如果 d 为偶数, 则 d/2 转方向即可;
    2.如果 d 为奇数:
    (1:n+2)下一步回走,再下一步往前走,且 (d+1)/2 转方向: +1-2*(d+1)/2=-d
    (2:n+1)下一步往前走,且 (n+1+d)/2 转方向: n+1-2*(n+1+d)/2=-d
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        for (int i = 1;; i++)
        {
            sum += i;
            if (sum >= target)
            {
                int d = sum - target;
                if (d % 2 == 0)
                {
                    return i;
                }
                return (i + 1 + d) % 2 == 0 ? i + 1 : i + 2;
            }
        }
    }
};