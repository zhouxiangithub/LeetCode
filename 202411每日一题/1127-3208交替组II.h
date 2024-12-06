#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0, left = 0;
        // n - 1 + (k - 1)
        for (int i = 1; i <= n + k - 2; i++) {
            if (colors[i % n] == colors[(i - 1) % n]) {
                left = i;
            }
            if (i - left + 1 >= k) {
                res++;
            }
        }
        return res;
    }
};