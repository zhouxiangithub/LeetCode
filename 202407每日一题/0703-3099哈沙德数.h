#pragma once
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, bx = x;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return bx % sum ? -1 : sum;
    }
};