#pragma once
using namespace std;
#include <string>
#include <deque>

class Solution {
public:
    string finalString(string s) {
        deque<char> dq;
        bool head = false;
        for (char ch : s)
        {
            if (ch != 'i')
            {
                if (head)
                {
                    dq.push_front(ch);
                }
                else
                {
                    dq.push_back(ch);
                }
            }
            else
            {
                head = !head;
            }
        }
        string res = (head ? string{ dq.rbegin(),dq.rend() } : string{ dq.begin(),dq.end() });
        return res;
    }
};

class Solution {
public:
    string finalString(string s) {
        int n = s.length(), cnt = count(s.begin(), s.end(), 'i');
        string res(n - cnt, ' ');
        for (int i = 0, j = n - cnt - 1, idx = n - 1, isReversal = false; idx >= 0; idx--)
        {
            if (s[idx] == 'i')
            {
                isReversal = !isReversal;
                continue;
            }
            if (isReversal)
            {
                res[i++] = s[idx];
            }
            else
            {
                res[j--] = s[idx];
            }
        }
        return res;
    }
};