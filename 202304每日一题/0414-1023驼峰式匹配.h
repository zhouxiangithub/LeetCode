#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; i++)
        {
            int idx_p = 0;
            for (auto c : queries[i])
            {
                if (idx_p < pattern.size() && pattern[idx_p] == c)
                {
                    idx_p++;
                }
                else if (isupper(c))
                {
                    res[i] = false;
                    break;
                }
            }
            if (idx_p < pattern.size())
            {
                res[i] = false;
            }
        }
        return res;
    }
};