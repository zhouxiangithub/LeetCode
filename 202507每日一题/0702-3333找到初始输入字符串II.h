#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    记 f(i,j) 表示考虑用 freq 中下标小于等于 i 的部分构造字符串，并且构造的字符串长度等于 j 的方案数
    f(i,j) = SUM(j'=1,freq(i))f(i-1,j-j')

    前缀和：g(i-1,j) = SUM(j'=0,j)f(i-1,j')

    ==> f(i,j) = g(i-1,j-1) - g(i-1,j-freq(i)-1)
*/
class Solution {
private: 
    static const int mod = 1000000007;
public:
    int possibleStringCount(string word, int k) {
        if (word.length() == k) {
            return 1;
        }

        int n = word.length();
        int cnt = 1;
        vector<int> freq;
        for (int i = 0; i < n - 1; i++) {
            if (word[i] == word[i + 1]) {
                cnt++;
            }
            else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int res = 1;
        for (int ct : freq) {
            res = static_cast<long long>(res) * ct % mod;
        }

        if (freq.size() >= k) {
            return res;
        }

        vector<int> f(k), g(k, 1);
        f[0] = 1;
        for (int i = 0; i < freq.size(); i++) {
            vector<int> fNew(k);
            for (int j = 1; j < k; j++) {
                fNew[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    fNew[j] = (g[j - 1] - g[j - freq[i] - 1] + mod) % mod;
                }
            }
            vector<int> gNew(k);
            gNew[0] = fNew[0];
            for (int j = 1; j < k; j++) {
                gNew[j] = (gNew[j - 1] + fNew[j]) % mod;
            }
            f = move(fNew);
            g = move(gNew);
        }
        return (res - g[k - 1] + mod) % mod;
    }
};