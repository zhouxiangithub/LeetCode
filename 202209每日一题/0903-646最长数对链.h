#pragma once
using namespace std;
#include <vector>
#include <algorithm>

//动态规划：定义dp[i]为以pairs[i]为结尾的最长数对链的长度
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};

//最长递增子序列：贪心+二分查找
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> arr; //arr[i]表示长度为i+1的数对链的末尾可以取得的最小值
        for (auto p : pairs)
        {
            int x = p[0], y = p[1];
            if (arr.size() == 0 || x > arr.back())
            {
                arr.emplace_back(y);
            }
            else
            {
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }
};

//贪心：挑选第二个数字最小的
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int curr = INT_MIN, res = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; });
        for (auto& p : pairs)
        {
            if (curr < p[0])
            {
                curr = p[1];
                res++;
            }
        }
        return res;
    }
};