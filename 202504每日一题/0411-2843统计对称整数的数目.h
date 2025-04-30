#pragma once
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int x = low; x <= high; x++) {
            if (x < 100 && x % 11 == 0) {
                res++;
            }
            else if (x > 1000) {
                int left = x / 1000 + (x % 1000) / 100;
                int right = (x % 100) / 10 + x % 10;
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
};