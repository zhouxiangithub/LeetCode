#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int pre = 0, suf = 0;
        int res = 0, minCost = 0;
        for (int i = 0; i <= n; i++) {
            if (pre + suf < minCost) {
                minCost = pre + suf;
                res = i;
            }
            if (i < n && customers[i] == 'N') {
                pre++;
            }
            else {
                suf--;
            }
        }
        return res;
    }
};