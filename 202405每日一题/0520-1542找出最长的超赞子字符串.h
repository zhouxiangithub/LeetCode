#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        unordered_map<int, int> prefix = { {0,-1} };
        int ans = 0, seq = 0;
        for (int i = 0; i < n; i++) {
            //前缀子字符串处理
            int digit = s[i] - '0';
            seq ^= (1 << digit);
            if (prefix.count(seq)) { //本身
                ans = max(ans, i - prefix[seq]);
                //求最长保存最小的那个idx即可,故此处不更新prefix
            }
            else {
                prefix[seq] = i;
            }
            //[j,i]回文:[0,i]和[0,j-1]最多只有一位不同
            for (int j = 0; j < 10; j++) {
                if (prefix.count(seq ^ (1 << j))) {
                    ans = max(ans, i - prefix[seq ^ (1 << j)]);
                }
            }
        }
        return ans;
    }
};