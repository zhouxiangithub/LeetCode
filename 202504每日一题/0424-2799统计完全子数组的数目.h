#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

// »¬¶¯´°¿Ú
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinctCnt = distinct.size();

        int right = 0;
        unordered_map<int, int> cnt;

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                cnt[nums[left - 1]]--;
                if (cnt[nums[left - 1]] == 0) {
                    cnt.erase(nums[left - 1]);
                }
            }
            while (right < n && cnt.size() < distinctCnt) {
                cnt[nums[right]]++;
                right++;
            }
            if (cnt.size() == distinctCnt) {
                res += (n - right + 1); // 1+[(n-1)-right+1]
            }
        }
        return res;
    }
};