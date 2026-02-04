#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int maxValue = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            int delta = arr[i + 1] - arr[i];
            if (delta < maxValue) {
                maxValue = delta;
                res = { {arr[i], arr[i + 1]} };
            }
            else if (delta == maxValue) {
                res.emplace_back(initializer_list<int>{ arr[i], arr[i + 1] });
            }
        }
        return res;
    }
};