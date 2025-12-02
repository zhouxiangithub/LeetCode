#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int oneCnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                while ((i + 1) < n && s[i + 1] == '0') {
                    i++;
                }
                res += oneCnt;
            }
            else {
                oneCnt++;
            }
        }
        return res;
    }
};