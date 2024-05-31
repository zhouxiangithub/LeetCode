#pragma once
using namespace std;
#include <unordered_map>

class Solution {
private:
    unordered_map<int, int> memo;
public:
    int minDays(int n) {
        if (n <= 1) {
            return n;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        return memo[n] = min(n % 2 + minDays(n / 2) + 1, n % 3 + minDays(n / 3) + 1);
    }
};