#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;
        for (int d = 1; num1 && num2 && num3; d *= 10) {
            key += min(min(num1 % 10, num2 % 10), num3 % 10) * d;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return key;
    }
};