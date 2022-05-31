#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    //���㣨�������ڵ�curr���ж��ٱ�nС���ӽڵ�
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