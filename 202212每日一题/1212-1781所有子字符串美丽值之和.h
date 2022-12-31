#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < n; j++)
            {
                cnt[s[j] - 'a']++;
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                int minFreq = n;
                for (int k = 0; k < 26; k++)
                {
                    if (cnt[k] > 0)
                    {
                        minFreq = min(minFreq, cnt[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }
        return res;
    }
};