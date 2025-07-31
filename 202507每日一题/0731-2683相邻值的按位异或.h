#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (int x : derived) {
            res ^= x;
        }
        return res == 0;
    }
};