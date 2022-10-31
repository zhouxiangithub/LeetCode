#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    void dfs(string& s, int pos, vector<string>& res)
    {
        while (pos < s.size() && isdigit(s[pos]))
        {
            pos++;
        }
        if (pos == s.size())
        {
            res.emplace_back(s);
            return;
        }
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int m = 0;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                m++;
            }
        }
        vector<string> ans;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            string str;
            for (int j = 0, k = 0; j < n; j++)
            {
                if (isalpha(s[j]) && (mask & (1 << k++)))
                {
                    str.push_back(toupper(s[j]));
                }
                else
                {
                    str.push_back(tolower(s[j]));
                }
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};