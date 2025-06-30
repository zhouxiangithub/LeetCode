#pragma once
using namespace std;
#include <string>
#include <vector>
#include <functional>

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string res, str;
        vector<int> cnt(26);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        for (int i = 25; i >= 0; i--) {
            str.insert(str.end(), cnt[i] / k, 'a' + i);
        }

        permuteFunc(str, [&](const string& seq) {
            if (seq.length() > res.length() || (seq.length() == res.length() && seq > res)) {
                if (isSubsequence(seq, k, s)) {
                    res = seq;
                }
            }
            });
        return res;
    }

    // 判断seq*k是否为s的子序列
    bool isSubsequence(const string& seq, int k, const string& s) {
        int n = seq.length();
        int i = 0;
        for (char ch : s) {
            if (seq[i % n] == ch) {
                i++;
                if (i == n * k) {
                    return true;
                }
            }
        }
        return false;
    }

    // 全排列
    void permuteFunc(const string& str, function<void(const string&)> f) {
        int n = str.length();
        string path;
        vector<int> vis(n);
        function<void()> dfs = [&]() {
            f(path);
            if (path.length() == n) {
                return;
            }
            for (int i = 0; i < n; i++) {
                if (vis[i] || (i > 0 && str[i] == str[i - 1] && !vis[i - 1])) {
                    continue;
                }
                path += str[i];
                vis[i] = 1;
                dfs();
                vis[i] = 0;
                path.pop_back();
            }
        };
        dfs();
    }
};