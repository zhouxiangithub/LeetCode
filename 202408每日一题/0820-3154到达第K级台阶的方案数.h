#pragma once
using namespace std;

/*
    n�β���2,����:2^0+2^1+...+2^(n-1)=2^n-1
    ÿ���β���2֮����Բ���һ�β���1
    [2^n-1-(n+1), 2^n-1] ==> [2^n-n-1, 2^n] (��ʼλ����̨��1)
*/
class Solution {
public:
    int waysToReachStair(int k) {
        auto comb = [](int n, int k)->int {
            long long ans = 1;
            for (int i = n; i >= n - k + 1; i--) {
                ans *= i;
                ans /= n - i + 1;
            }
            return ans;
        };

        int n = 0, npow = 1, ans = 0;
        while (true) {
            if (k >= npow - n - 1 && k <= npow) {
                ans += comb(n + 1, npow - k);
            }
            else if (k < npow - n - 1) {
                break;
            }
            n++;
            npow *= 2;
        }
        return ans;
    }
};