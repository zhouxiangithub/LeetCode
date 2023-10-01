#pragma once
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int quo = time / (n - 1);
        int rem = time % (n - 1);
        return quo % 2 ? (n - rem) : (rem + 1);
    }
};