#pragma once
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int n = num, res = 0;
        while (n)
        {
            if (num % (n % 10) == 0)
            {
                res += 1;
            }
            n /= 10;
        }
        return res;
    }
};