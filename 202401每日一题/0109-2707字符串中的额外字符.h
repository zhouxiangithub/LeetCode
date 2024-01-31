#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX); //d[i]为s[0,1,...,i-1]子问题
        unordered_map<string, int> mp;
        for (auto dic : dictionary)
        {
            mp[dic]++;
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            d[i] = d[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (mp.count(s.substr(j, i - j)))
                {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};