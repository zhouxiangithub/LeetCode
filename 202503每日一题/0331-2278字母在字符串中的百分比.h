#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for (char c : s) {
            if (c == letter) {
                cnt++;
            }
        }
        return 100 * cnt / n;
    }
};