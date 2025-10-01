#pragma once
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 <= num2) {
            return -1;
        }

        int cnt = 1;
        while (true) {
            long long x = num1 - static_cast<long long>(num2) * cnt;
            if (x < cnt) {
                return -1;
            }
            if (__builtin_popcountll(x) <= cnt) {
                return cnt;
            }
            cnt++;
        }
    }
};