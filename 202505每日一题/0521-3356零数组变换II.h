#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        if (!check(nums, queries, right)) {
            return -1;
        }
        while (left < right) {
            int k = left + (right - left) / 2;
            if (check(nums, queries, k)) {
                right = k;
            }
            else {
                left = k + 1;
            }
        }
        return left;
    }

    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> arr(nums.size() + 1, 0);
        for (int i = 0; i < k; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int value = queries[i][2];
            arr[left] += value;
            arr[right + 1] -= value;
        }
        vector<int> count;
        int cur = 0;
        for (int a : arr) {
            cur += a;
            count.push_back(cur);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);
        int count = 0;
        int q = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            count += arr[i];
            while (q < queries.size() && count < num) {
                int left = queries[q][0];
                int right = queries[q][1];
                int value = queries[q][2];
                arr[left] += value;
                arr[right + 1] -= value;
                if (left <= i && i <= right) {
                    count += value;
                }
                q++;
            }
            if (count < num) {
                return -1;
            }
        }
        return q;
    }
};