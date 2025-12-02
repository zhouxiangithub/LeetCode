#pragma once
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int remain = 1 % k, res = 1;
        while (remain) {
            remain = (remain * 10 + 1) % k;
            res++;
        }
        return res;
    }
};