#pragma once
using namespace std;
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> uSet;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long res = stoll(s);
            if (res % k == 0) {
                sort(s.begin(), s.end());
                uSet.emplace(s); // 去重
            }
        }

        vector<long long> f(n + 1, 1); // f[n] = n!
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i;
        }

        /**
        * n = c0 + c1 + ... + c9
        * 
        * 考虑不得有前导0
        * 
        * C(n-1,c0) * C(n-c0,c1) * ... * C(n-c0-c1-...-c8,c9)
        * 
        *   (n-1)!         *    (n-c0)!        * ... *   (n-c0-c1-...-c8)!   
        * c0! * (n-1-c0)!  * c1! * (n-c0-c1)!  * ... * c9! * (n-c0-c1-...-c8-c9)!
        * 
        *   (n-1)!         *    (n-c0)
        * c0!              * c1!               * ... * c9!
        */
        long long ans = 0;
        for (const string& str : uSet) {
            vector<int> cnt(10);
            for (char ch : str) {
                cnt[ch - '0']++;
            }
            long long tol = (n - cnt[0]) * f[n - 1];
            for (int x : cnt) {
                tol /= f[x];
            }
            ans += tol;
        }
        return ans;
    }
};