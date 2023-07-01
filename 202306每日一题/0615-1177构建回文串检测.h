#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> count(n + 1);
        for (int i = 0; i < n; i++)
        {
            count[i + 1] = count[i] ^ (1 << (s[i] - 'a'));
        }
        vector<bool> res;
        for (auto& query : queries)
        {
            int l = query[0], r = query[1], k = query[2];
            int bits = 0, x = count[r + 1] ^ count[l];
            while (x > 0)
            {
                x &= x - 1;
                bits++;
            }
            res.push_back(bits <= 2 * k + 1); //替换k次可以保证使得长度最长为2k+1的字符串变成回文串
        }
        return res;
    }
};