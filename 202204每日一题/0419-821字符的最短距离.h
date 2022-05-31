#pragma once
using namespace std;
#include <vector>
#include <string>

/*
    ��s��ÿ���±�i����s[i]�������/�Ҳ�������ַ�c�ľ���
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n);

        for (int i = 0, index = -n; i < n; i++)
        {
            if (s[i] == c)
            {
                index = i;
            }
            ans[i] = i - index;
        }

        for (int i = n - 1, index = 2 * n; i >= 0; i--)
        {
            if (s[i] == c)
            {
                index = i;
            }
            ans[i] = min(ans[i], index - i);
        }

        return ans;
    }
};