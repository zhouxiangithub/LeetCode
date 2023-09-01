#pragma once
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, sum = 0;
        while (n)
        {
            int x = n % 10;
            n /= 10;
            mul *= x;
            sum += x;
        }
        return mul - sum;
    }
};