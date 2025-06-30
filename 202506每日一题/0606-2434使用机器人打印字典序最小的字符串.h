#pragma once
using namespace std;
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        // 预处理：sufMin[i]表示s[i+1,n-1]中字符最小值
        vector<char> sufMin(n);
        sufMin[n - 1] = 'z' + 1;
        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = min(sufMin[i + 1], s[i + 1]);
        }

        string res;
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            stk.push(s[i]);
            while (!stk.empty() && stk.top() <= sufMin[i]) {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};