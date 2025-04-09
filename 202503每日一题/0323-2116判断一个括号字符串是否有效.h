#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int mx = 0; // 可达的最大分数
        int mn = 0; // 所需的最小分数
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                // s[i]无法更改
                int diff;
                if (s[i] == '(') {
                    diff = 1;
                }
                else {
                    diff = -1;
                }
                mx += diff;
                mn = max(mn + diff, (i + 1) % 2);
            }
            else {
                // s[i]可以更改
                mx++;
                mn = max(mn - 1, (i + 1) % 2);
            }
            if (mx < mn) {
                return false;
            }
        }
        return mn == 0;
    }
};