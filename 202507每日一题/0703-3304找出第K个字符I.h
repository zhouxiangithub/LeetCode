#pragma once
using namespace std;
#include <string>

class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while (res.length() < 500) {
            string tmp = res;
            for (int i = 0; i < res.length(); i++) {
                tmp.push_back(res[i] + 1);
            }
            res = tmp;
        }
        return res[k - 1];
    }
};

class Solution {
public:
    char kthCharacter(int k) {
        int cnt = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k -= (1 << t);
            cnt++;
        }
        return 'a' + cnt;
    }
};