#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int x = sqrt(t);
        if (x * x == t)
        {
            return x;
        }
        return -1;
    }
};