#pragma once
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

//从头遍历给定的字符串。当我们遇到 1 时计数器加 1，遇到 0 时计数器减 1。当计数器为 0 时，我们就拆分除了一个「整体」的特殊序列。
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2)
        {
            return s;
        }
        int cnt = 0, left = 0;
        vector<string> subs;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    subs.emplace_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }
        sort(subs.begin(), subs.end(), greater<string>{});
        string ans = accumulate(subs.begin(), subs.end(), string(""));
        return ans;
    }
};