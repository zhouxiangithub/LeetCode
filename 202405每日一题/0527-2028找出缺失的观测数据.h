#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        int sumM = 0;
        for (int& roll : rolls) {
            sumM += roll;
        }
        int sumN = sum - sumM;
        if (sumN < n || sumN>6 * n) {
            return {};
        }
        int quo = sumN / n, rem = sumN % n;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = quo + (i < rem ? 1 : 0);
        }
        return res;
    }
};