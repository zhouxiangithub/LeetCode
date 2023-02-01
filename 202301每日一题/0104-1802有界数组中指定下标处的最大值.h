#pragma once
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (valid(mid, n, index, maxSum))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    bool valid(int mid, int n, int index, int maxSum)
    {
        int left_len = index;
        int right_len = n - 1 - index;
        return mid + cal(mid, left_len) + cal(mid, right_len) <= maxSum;
    }

    long cal(int value, int length)
    {
        if (length + 1 < value)
        {
            //value-1, value-2, ..., value-length
            int end = value - length;
            return (long)(value - 1 + end) * length / 2;
        }
        else
        {
            //1, 1, ..., 1, 2, ..., value-1
            int begin_sum = length - (value - 1);
            return (long)value * (value - 1) / 2 + begin_sum;
        }
    }
};