#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int sum = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
        return sum / (n * 0.9);
    }
};