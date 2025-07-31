#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int cnt = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k -= ((long long)1 << t);
            if (operations[t]) {
                cnt++;
            }
        }
        return 'a' + (cnt % 26);
    }
};