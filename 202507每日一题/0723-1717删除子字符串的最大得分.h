#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'a') {
                    s[i] = 'b';
                }
                else if (s[i] == 'b') {
                    s[i] = 'a';
                }
            }
        }
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int cntA = 0, cntB = 0;
            while (i < s.length() && (s[i] == 'a' || s[i] == 'b')) {
                if (s[i] == 'a') {
                    cntA++;
                }
                else {
                    if (cntA > 0) {
                        cntA--;
                        res += x;
                    }
                    else {
                        cntB++;
                    }
                }
                i++;
            }
            res += min(cntA, cntB) * y;
        }
        return res;
    }
};