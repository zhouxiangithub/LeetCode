#pragma once
using namespace std;

/*
    n次操作2,向上:2^0+2^1+...+2^(n-1)=2^n-1
    每两次操作2之间可以插入一次操作1
    [2^n-1-(n+1), 2^n-1] ==> [2^n-n-1, 2^n] (起始位置在台阶1)
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