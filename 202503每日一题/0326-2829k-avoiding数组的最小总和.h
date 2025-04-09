#pragma once
using namespace std;

class Solution {
private:
    // [first + (first + count - 1)] * count / 2
    int sumHelper(int first, int count) {
        return (2 * first + count - 1) * count / 2;
    }
public:
    int minimumSum(int n, int k) {
        if (n <= k / 2) {
            return sumHelper(1, n);
        }
        else {
            return sumHelper(1, k / 2) + sumHelper(k, n - k / 2);
        }
    }
};