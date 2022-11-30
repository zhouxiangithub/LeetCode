#pragma once
using namespace std;
#include <algorithm>

/*
    sum = 1+2+...+n > target, d = sum - target
    1.��� d Ϊż��, �� d/2 ת���򼴿�;
    2.��� d Ϊ����:
    (1:n+2)��һ������,����һ����ǰ��,�� (d+1)/2 ת����: +1-2*(d+1)/2=-d
    (2:n+1)��һ����ǰ��,�� (n+1+d)/2 ת����: n+1-2*(n+1+d)/2=-d
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