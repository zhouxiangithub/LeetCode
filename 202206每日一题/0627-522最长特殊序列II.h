#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto is_subseq = [](const string& s, const string& t)->bool {
            int s_idx = 0, t_idx = 0;
            while (s_idx < s.size() && t_idx < t.size())
            {
                if (s[s_idx] == t[t_idx])
                {
                    s_idx++;
                }
                t_idx++;
            }
            return s_idx == s.size();
        };

        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            bool check = true;
            for (int j = 0; j < n; j++)
            {
                if (i != j && is_subseq(strs[i], strs[j]))
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans;
    }
};