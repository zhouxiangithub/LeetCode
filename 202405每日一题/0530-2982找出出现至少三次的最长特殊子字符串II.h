#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int maximumLength(string s) {
        int res = -1;
        int n = s.size();
        unordered_map<char, vector<int>> cnt;
        for (int i = 0, j = 0; i < n;) {
            while (j < n && s[j] == s[i]) {
                j++;
            }
            cnt[s[i]].emplace_back(j - i);
            i = j;
        }

        for (auto& [_, vec] : cnt) {
            int lo = 1, hi = n - 2; //最小长度和最大可能长度
            while (lo <= hi) {
                int mid = (hi - lo) / 2 + lo;
                int count = 0;
                for (int len : vec) {
                    if (len >= mid) {
                        count += len - mid + 1;
                    }
                }
                if (count >= 3) {
                    res = max(res, mid);
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> cnt(26, vector<int>(3));
        for (int i = 0, j = 0; i < n;) {
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int ch = s[i] - 'a';
            int len = j - i;
            if (len > cnt[ch][0]) {
                cnt[ch][2] = cnt[ch][1];
                cnt[ch][1] = cnt[ch][0];
                cnt[ch][0] = len;
            }
            else if (len > cnt[ch][1]) {
                cnt[ch][2] = cnt[ch][1];
                cnt[ch][1] = len;
            }
            else if (len > cnt[ch][2]) {
                cnt[ch][2] = len;
            }
            i = j;
        }

        int res = 0;
        for (auto vec : cnt) {
            res = max({ res,vec[0] - 2,min(vec[0] - 1,vec[1]),vec[2] });
        }

        return res ? res : -1;
    }
};