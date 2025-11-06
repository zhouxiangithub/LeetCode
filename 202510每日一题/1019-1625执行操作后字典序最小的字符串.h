#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        vector<int> vis(n);
        string res = s;
        s = s + s; // ÑÓ³¤×Ö·û´®·½±ã½ØÈ¡
        for (int i = 0; vis[i] == 0; i = (i + b) % n) {
            vis[i] = 1;
            for (int j = 0; j < 10; j++) {
                int kLimit = (b % 2 == 0 ? 0 : 9);
                for (int k = 0; k <= kLimit; k++) {
                    string tmp = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        tmp[p] = '0' + (tmp[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        tmp[p] = '0' + (tmp[p] - '0' + k * a) % 10;
                    }
                    res = min(res, tmp);
                }
            }
        }
        return res;
    }
};