#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int j = 0; j < strs[0].length(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};