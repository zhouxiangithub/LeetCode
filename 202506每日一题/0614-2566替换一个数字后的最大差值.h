#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int minMaxDifference(int num) {
        auto replace = [](string& s, char x, char y) {
            for (char& ch : s) {
                if (ch == x) {
                    ch = y;
                }
            }
        };

        string minNum = to_string(num);
        string maxNum = to_string(num);
        for (char ch : maxNum) {
            if (ch != '9') {
                replace(maxNum, ch, '9');
                break;
            }
        }
        replace(minNum, minNum[0], '0');
        return stoi(maxNum) - stoi(minNum);
    }
};