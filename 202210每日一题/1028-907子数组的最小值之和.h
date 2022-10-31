#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> stack;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && arr[i] <= arr[stack.back()])
            {
                stack.pop_back();
            }
            left[i] = i - (stack.empty() ? -1 : stack.back());
            stack.emplace_back(i);
        }
        stack.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack.empty() && arr[i] < arr[stack.back()])
            {
                stack.pop_back();
            }
            right[i] = (stack.empty() ? n : stack.back()) - i;
            stack.emplace_back(i);
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        return ans;
    }
};