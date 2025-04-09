#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, minCnt = 0;
        for (char c : s) {
            if (c == '[') {
                cnt++;
            }
            else {
                cnt--;
                minCnt = min(minCnt, cnt);
            }
        }
        return (-minCnt + 1) / 2;
    }
};