#pragma once
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, day = n % 7;
        int res = 28 * week + 7 * ((week - 1) * week / 2);
        for (int i = week + 1; i <= week + day; i++) {
            res += i;
        }
        return res;
    }
};