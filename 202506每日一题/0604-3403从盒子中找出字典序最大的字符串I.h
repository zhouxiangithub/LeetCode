#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = lastSubstring(word);
        return last.substr(0, min(last.length(), word.length() - numFriends + 1));
    }

    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.length();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[j + k] > s[i + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            }
            else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }
};