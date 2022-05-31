#pragma once
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = 2;
        while (n)
        {
            int cur = n % 2;
            if (cur == pre)
            {
                return false;
            }
            pre = cur;
            n /= 2;
        }
        return true;
    }
};