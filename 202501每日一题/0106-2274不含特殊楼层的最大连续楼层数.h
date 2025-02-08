#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        if (n == top - bottom + 1) {
            return 0;
        }

        int ans = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        for (int i = 1; i < n + 2; i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};