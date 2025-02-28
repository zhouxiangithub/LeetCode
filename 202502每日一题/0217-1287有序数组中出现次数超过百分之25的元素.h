#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int count = n / 4;
        for (int i = 0; i < n - count; i++) {
            if (arr[i] == arr[i + count]) {
                return arr[i];
            }
        }
        return -1;
    }
};