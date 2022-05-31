#pragma once
using namespace std;
#include <vector>
#include <numeric>

/*
    f(i)   ==> [a(n-i),...,a(n-1),a0,a1,a2,...,a(n-i-1)]
    f(i+1) ==> [a(n-i-1),a(n-i),...,a(n-1),a0,a1,a2,...,a(n-i-2)]
    f(i+1) - f(i) = a0+a1+a2+...+a(n-1)-n*a(n-i-1), i>=0
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
        {
            f += i * nums[i];
        }
        int res = f;
        /*
            f1 = f0 + sum - n*a(n-1)
            f(n-1) = f(n-2) + sum - n*a1
        */
        for (int i = n - 1; i > 0; i--)
        {
            f += sum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};