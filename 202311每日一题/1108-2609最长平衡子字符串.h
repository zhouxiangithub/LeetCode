#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, n = s.size();
        vector<int> count(2);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count[1]++;
                res = max(res, 2 * min(count[0], count[1]));
            }
            else if (i == 0 || s[i - 1] == '1')
            {
                count[0] = 1;
                count[1] = 0;
            }
            else
            {
                count[0]++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, n = s.size();
        int cnt0 = 0, cnt1 = 0;
        int i = 0, j = 0;
        while (i < n)
        {
            while (j < n && s[j] == '0')
            {
                j++;
            }
            cnt0 = j - i;
            i = j;
            while (j < n && s[j] == '1')
            {
                j++;
            }
            cnt1 = j - i;
            res = max(res, 2 * min(cnt0, cnt1));
            i = j;
        }
        return res;
    }
};