#pragma once
using namespace std;
#include <algorithm>

/*
    ��n�����Ʊ�ʾ�ĵ�λ��ʼ���б���
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