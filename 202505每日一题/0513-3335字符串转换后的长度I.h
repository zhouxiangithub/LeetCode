#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
private:
    static const int mod = 1000000007;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (int round = 0; round < t; round++) {
            vector<int> next(26);
            next[0] = cnt[25]; // z -> (a)b
            next[1] = (cnt[25] + cnt[0]) % mod; // z -> a(b)  a -> b
            for (int i = 2; i < 26; i++) {
                next[i] = cnt[i - 1];
            }
            cnt = move(next);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }
};