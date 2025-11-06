#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        unordered_map<int, int> numCount;

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                res = max(res, i - lastNumIndex);
                lastNumIndex = i;
            }
        }
        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        res = max(res, (int)nums.size() - lastNumIndex);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                }
                else {
                    left = mid;
                }
            }
            return left;
        };

        for (int i = nums.front(); i <= nums.back(); i++) {
            int left = leftBound(i - k);
            int right = rightBound(i + k);

            int tmpRes;
            if (numCount.count(i)) {
                tmpRes = min(right - left + 1, numCount[i] + numOperations);
            }
            else {
                tmpRes = min(right - left + 1, numOperations);
            }
            res = max(res, tmpRes);
        }

        return res;
    }
};