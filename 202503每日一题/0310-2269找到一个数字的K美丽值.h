#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        int n = to_string(num).size();
        for (int i = 0; i <= n - k; i++) {
            int tmp = stoi(to_string(num).substr(i, k));
            if (tmp && (num % tmp == 0)) {
                res++;
            }
        }
        return res;
    }
};