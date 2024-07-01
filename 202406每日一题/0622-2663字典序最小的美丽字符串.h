#pragma once
using namespace std;
#include <string>
#include <unordered_set>

/*
    任何长度为2或者更长的回文字符串都包含一个长度为2或者3的回文字符串
    因此只要一个字符串中的任何字符都不与它前两个字符相同即可
*/
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        for (int i = s.length() - 1; i >= 0; i--) {
            unordered_set<char> setChar;
            for (int j = 1; j <= 2; j++) { //前两个
                if (i - j >= 0) {
                    setChar.insert(s[i - j]);
                }
            }
            for (int j = 1; j <= 3; j++) {
                if (s[i] - 'a' + 1 + j <= k && setChar.find(s[i] + j) == setChar.end()) { //找到第一个改变的idx
                    return generate(s, i, j);
                }
            }
        }
        return "";
    }

    string generate(string s, int idx, int offset) {
        s[idx] += offset;
        for (int i = idx + 1; i < s.length(); i++) {
            unordered_set<char> setChar;
            for (int j = 1; j <= 2; j++) {
                if (i - j >= 0) {
                    setChar.insert(s[i - j]);
                }
            }
            for (int j = 0; j <= 2; j++) {
                if (setChar.find('a' + j) == setChar.end()) {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
        return s;
    }
};