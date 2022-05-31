#pragma once
using namespace std;
#include <math.h>

/*
    ��������nλ�����ĳ˻������Ǹ�2nλ�������ǿ��Դ�10^n-1��ʼö�ٻ���������벿��
*/
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
        {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; left--) //ö�ٻ���������벿��
        {
            long p = left;
            for (int i = left; i > 0; i /= 10)
            {
                p = p * 10 + i % 10; //��ת��벿�ֵ�������ĩβ�����������p
            }
            for (long j = upper; j * j >= p; j--)
            {
                if (p % j == 0)
                {
                    return p % 1337;
                }
            }
        }
    }
};