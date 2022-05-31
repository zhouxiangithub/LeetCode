#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(), min = 0, max = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++)
        {
            ans[i] = s[i] == 'I' ? min++ : max--;
        }
        ans[n] = min; //只剩下最后一个数了
        return ans;
    }
};