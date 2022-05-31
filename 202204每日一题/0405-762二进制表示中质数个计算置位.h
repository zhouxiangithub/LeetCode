#pragma once
using namespace std;

class Solution {
    //�ж�һ�����Ƿ�Ϊ����
    bool isPrime(int x)
    {
        if (x < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    //����һ��32λ�޷��������ж��ٸ�λΪ1
    //__builtin_popcount
    unsigned popcnt(unsigned u)
    {
        unsigned ret = 0;
        while (u)
        {
            u = (u & (u - 1));
            ret++;
        }
        return ret;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; x++)
        {
            if (isPrime(popcnt(x)))
            {
                ans++;
            }
        }
        return ans;
    }
};