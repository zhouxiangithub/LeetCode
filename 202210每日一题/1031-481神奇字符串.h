#pragma once
using namespace std;
#include <string>

/*
    1 22 11 2 1 22 1 22 11 2 11 22 ...
    1 2 2 1 1 2 1 2 2 1 2 2 ...
    用指针 i 来指向现在需要构造的对应的组的大小
    用指针 j 来指向现在需要构造的对应组的位置
*/
class Solution {
public:
    int magicalString(int n) {
        if (n < 4)
        {
            return 1;
        }
        string s(n, '0');
        s[0] = '1', s[1] = '2', s[2] = '2';
        int res = 1;
        int i = 2, j = 3;
        while (j < n)
        {
            int size = s[i] - '0';
            int num = 3 - (s[j - 1] - '0');
            while (size > 0 && j < n)
            {
                s[j] = num + '0';
                if (num == 1)
                {
                    res++;
                }
                j++;
                size--;
            }
            i++;
        }
        return res;
    }
};