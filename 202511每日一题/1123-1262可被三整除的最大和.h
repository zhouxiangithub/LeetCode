#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v[3];
        for (int num : nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int res = 0;
        int size1 = v[1].size(), size2 = v[2].size();
        for (int j = size1 - 2; j <= size1; j++) {
            if (j >= 0) {
                for (int k = size2 - 2; k <= size2; k++) {
                    if (k >= 0 && (j - k) % 3 == 0) {
                        res = max(res, accumulate(v[1].begin(), v[1].begin() + j, 0) + accumulate(v[2].begin(), v[2].begin() + k, 0));
                    }
                }
            }
        }
        return res + accumulate(v[0].begin(), v[0].end(), 0);
    }
};