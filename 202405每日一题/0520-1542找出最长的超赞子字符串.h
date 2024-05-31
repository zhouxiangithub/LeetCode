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
            //ǰ׺���ַ�������
            int digit = s[i] - '0';
            seq ^= (1 << digit);
            if (prefix.count(seq)) { //����
                ans = max(ans, i - prefix[seq]);
                //���������С���Ǹ�idx����,�ʴ˴�������prefix
            }
            else {
                prefix[seq] = i;
            }
            //[j,i]����:[0,i]��[0,j-1]���ֻ��һλ��ͬ
            for (int j = 0; j < 10; j++) {
                if (prefix.count(seq ^ (1 << j))) {
                    ans = max(ans, i - prefix[seq ^ (1 << j)]);
                }
            }
        }
        return ans;
    }
};