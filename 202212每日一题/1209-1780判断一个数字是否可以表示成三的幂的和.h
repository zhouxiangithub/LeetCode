#pragma once
using namespace std;

//n的3进制表示中每一位均不为2
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};