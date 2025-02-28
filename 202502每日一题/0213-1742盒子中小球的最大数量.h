#pragma once
using namespace std;
#include <unordered_map>

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, tmp = i;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            count[sum]++;
            res = max(res, count[sum]);
        }
        return res;
    }
};