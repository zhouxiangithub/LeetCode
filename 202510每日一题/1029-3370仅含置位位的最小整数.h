#pragma once
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;
        while (num < n) {
            num = num * 2 + 1;
        }
        return num;
    }
};