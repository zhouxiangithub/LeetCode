#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; k++)
                {
                    diff += ((s[i + k] == t[j + k]) ? 0 : 1);
                    if (diff > 1)
                    {
                        break;
                    }
                    else if (diff == 1)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int ans = 0;
        vector<vector<int>> dpl(m + 1, vector<int>(n + 1)); //左侧连续相等的最大长度
        vector<vector<int>> dpr(m + 1, vector<int>(n + 1)); //右侧连续相等的最大长度
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dpl[i + 1][j + 1] = ((s[i] == t[j]) ? (dpl[i][j] + 1) : 0);
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dpr[i][j] = ((s[i] == t[j]) ? (dpr[i + 1][j + 1] + 1) : 0);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i] != t[j])
                {
                    ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};