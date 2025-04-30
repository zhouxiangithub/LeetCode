#pragma once
using namespace std;
#include <unordered_map>

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> uMap;
        int maxValue = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0, tmp = i;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            uMap[sum]++;
            maxValue = max(maxValue, uMap[sum]);
        }
        int res = 0;
        for (auto& [_, v] : uMap) {
            if (v == maxValue) {
                res++;
            }
        }
        return res;
    }
};