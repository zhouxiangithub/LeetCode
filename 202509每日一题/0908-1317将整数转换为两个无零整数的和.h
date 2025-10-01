#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int x = 1; x < n; x++) {
            int y = n - x;
            if (to_string(x).find('0') == string::npos && to_string(y).find('0') == string::npos) {
                return { x,y };
            }
        }
        return {};
    }
};