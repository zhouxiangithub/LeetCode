#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int maxDiff(int num) {
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
        for (int i = 0; i < minNum.size(); i++) {
            char ch = minNum[i];
            if (i == 0) {
                if (ch != '1') {
                    replace(minNum, ch, '1');
                    break;
                }
            }
            else {
                if (ch != '0' && ch != minNum[0]) {
                    replace(minNum, ch, '0');
                    break;
                }
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};