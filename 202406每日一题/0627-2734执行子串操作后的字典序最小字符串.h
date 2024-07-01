#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string smallestString(string s) {
        bool found = false;
        for (int i = 0; i < s.length(); i++) {
            if (!found && s[i] != 'a') {
                s[i] = s[i] - 1;
                found = true;
                continue;
            }
            if (found && s[i] == 'a') {
                break;
            }
            if (found && s[i] != 'a') {
                s[i] = s[i] - 1;
            }
        }
        if (!found) {
            s[s.length() - 1] = 'z';
        }
        return s;
    }
};