#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        vector<int> sortedNums(uniqueNums.begin(), uniqueNums.end());
        sort(sortedNums.begin(), sortedNums.end());

        int res = n, j = 0;
        for (int i = 0; i < sortedNums.size(); i++) {
            int right = sortedNums[i] + n - 1;
            while (j < sortedNums.size() && sortedNums[j] <= right) {
                res = min(res, n - (j - i + 1));
                j++;
            }
        }

        return res;
    }
};