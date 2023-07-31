#pragma once
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while (n)
        {
            res += n % 10 * sign;
            sign = -sign;
            n /= 10;
        }
        return -sign * res;
    }
};