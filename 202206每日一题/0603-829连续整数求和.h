#pragma once
using namespace std;

/*
    ��С������k������1+2+...+k = k*(k+1)/2 <=n
    ����������k��������С����Ϊx����
    n = x+(x+1)+...+(x+k-1) = k*(2*x+k-1)/2
    ==> x = n/k-(k-1)/2
    (1)kΪ��������(k-1)Ϊż�������ԣ�k|n
    (2)kΪż������(k-1)Ϊ������(2*x+k-1)=2*n/kΪ���������ԣ�k������n��k|2*n
*/
class Solution {
public:
    bool isKConsecutive(int n, int k)
    {
        if (k % 2 == 1)
        {
            return n % k == 0;
        }
        else
        {
            return n % k != 0 && 2 * n % k == 0;
        }
    }

    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int k = 1; k * (k + 1) <= 2 * n; k++)
        {
            if (isKConsecutive(n, k))
            {
                ans++;
            }
        }
        return ans;
    }
};

/*
    n = x+(x+1)+...+(x+k-1) = k*(2*x+k-1)/2
      = k*x+k*(k-1)/2
    x>=1,k>=1
*/
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0, sum = 0;
        for (int i = 1; sum < n; i++)
        {
            if ((n - sum) % i == 0)
            {
                ans++;
            }
            sum += i;
        }
        return ans;
    }
};