#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int check(int num, vector<int>& tops, vector<int>& bottoms, int n) {
        int rotTop = 0, rotBot = 0;
        for (int i = 0; i < n; i++) {
            if (tops[i] != num && bottoms[i] != num) {
                return -1;
            }
            else if (tops[i] != num) {
                rotTop++;
            }
            else if (bottoms[i] != num) {
                rotBot++;
            }
        }
        return min(rotTop, rotBot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int res = check(tops[0], tops, bottoms, n);
        if (res == -1) {
            res = check(bottoms[0], tops, bottoms, n);
        }
        return res;
    }
};