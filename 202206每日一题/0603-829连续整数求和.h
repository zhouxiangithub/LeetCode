#pragma once
using namespace std;

/*
    最小的连续k个数：1+2+...+k = k*(k+1)/2 <=n
    假设连续的k个数中最小的数为x，则：
    n = x+(x+1)+...+(x+k-1) = k*(2*x+k-1)/2
    ==> x = n/k-(k-1)/2
    (1)k为奇数，则(k-1)为偶数，所以：k|n
    (2)k为偶数，则(k-1)为奇数，(2*x+k-1)=2*n/k为奇数，所以：k不整除n，k|2*n
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