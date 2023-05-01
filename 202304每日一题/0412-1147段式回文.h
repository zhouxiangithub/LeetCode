#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool judge(const string& text, int ll, int rl, int len)
    {
        while (len--)
        {
            if (text[ll] != text[rl])
            {
                return false;
            }
            ll++;
            rl++;
        }
        return true;
    }

    int longestDecomposition(string text) {
        int n = text.size();
        int res = 0;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int len = 1;
            while (l + (len - 1) < r - (len - 1))
            {
                if (judge(text, l, r - (len - 1), len))
                {
                    res += 2;
                    break;
                }
                len++;
            }
            if (l + (len - 1) >= r - (len - 1))
            {
                res++;
            }
            l += len;
            r -= len;
        }
        return res;
    }
};