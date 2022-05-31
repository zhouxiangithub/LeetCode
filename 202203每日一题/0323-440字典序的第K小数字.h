#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    //计算（包括）节点curr下有多少比n小的子节点
    int getSteps(int curr, long n)
    {
        int steps = 0;
        long left = curr;
        long right = curr;
        while (left <= n)
        {
            steps += min(right, n) - left + 1;
            left = left * 10;
            right = right * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0)
        {
            int steps = getSteps(curr, n);
            if (steps <= k)
            {
                k -= steps;
                curr++;
            }
            else
            {
                curr = curr * 10;
                k--;
            }
        }
        return curr;
    }
};