#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> d(n + 1, inf);
        unordered_map<char, int> mp;
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int maxCnt = 0;
            mp.clear();
            for (int j = i; j >= 1; j--) {
                mp[s[j - 1]]++;
                maxCnt = max(maxCnt, mp[s[j - 1]]);
                if (maxCnt * mp.size() == (i - j + 1) && d[j - 1] != inf) {
                    d[i] = min(d[i], d[j - 1] + 1);
                }
            }
        }
        return d[n];
    }
};