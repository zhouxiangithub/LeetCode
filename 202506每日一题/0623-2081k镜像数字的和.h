#pragma once
using namespace std;

class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x)->bool {
            int len = -1;
            while (x) {
                len++;
                digit[len] = x % k;
                x /= k;
            }
            for (int i = 0, j = len; i < j; i++, j--) {
                if (digit[i] != digit[j]) {
                    return false;
                }
            }
            return true;
        };

        long long res = 0;
        int count = 0, left = 1;
        while (count < n) {
            int right = left * 10;
            for (int op = 0; op < 2; op++) {
                // 对于 abc 先 abcba 再 abccba
                for (int i = left; i < right && count < n; i++) {
                    long long num = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x) {
                        num = num * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(num)) {
                        count++;
                        res += num;
                    }
                }
            }
            left = right;
        }
        return res;
    }
};