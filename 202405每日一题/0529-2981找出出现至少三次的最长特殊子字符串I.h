#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int n = s.size();

        vector<int> chs[26];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            if (i == n - 1 || s[i] != s[i + 1]) {
                int ch = s[i] - 'a';
                chs[ch].push_back(cnt);
                cnt = 0;

                //冒泡排序
                for (int j = chs[ch].size() - 1; j > 0; j--) {
                    if (chs[ch][j] > chs[ch][j - 1]) {
                        swap(chs[ch][j], chs[ch][j - 1]);
                    }
                    else {
                        break;
                    }
                }

                //保存前3大的长度即可
                if (chs[ch].size() > 3) {
                    chs[ch].pop_back();
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (chs[i].size() > 0 && chs[i][0] > 2) { //最大的长度大于2
                ans = max(ans, chs[i][0] - 2);
            }
            if (chs[i].size() > 1 && chs[i][0] > 1) { //至少有2个前3大的长度且最大的长度大于1
                ans = max(ans, min(chs[i][0] - 1, chs[i][1]));
            }
            if (chs[i].size() > 2) { //前3大的长度都有
                ans = max(ans, chs[i][2]);
            }
        }

        return ans;
    }
};