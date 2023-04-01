#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[i] != diff)
                {
                    continue;
                }
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[k] - nums[j] == diff)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// n, n+diff, n+2*diff
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> hashSet;
        for (int n : nums)
        {
            hashSet.emplace(n);
        }
        int ans = 0;
        for (int n : nums)
        {
            if (hashSet.count(n + diff) && hashSet.count(n + 2 * diff))
            {
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0, j = 1, k = 2; i < n - 2 && j < n - 1 && k < n; i++)
        {
            j = max(j, i + 1);
            while (j < n - 1 && nums[j] - nums[i] < diff)
            {
                j++;
            }
            if (j >= n - 1 || nums[j] - nums[i] > diff)
            {
                continue;
            }
            k = max(k, j + 1);
            while (k < n && nums[k] - nums[j] < diff)
            {
                k++;
            }
            if (k < n && nums[k] - nums[j] == diff)
            {
                ans++;
            }
        }
        return ans;
    }
};