#pragma once
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int pre = maxHeights[i];
            long long sum = pre;
            for (int j = i - 1; j >= 0; j--)
            {
                pre = min(pre, maxHeights[j]);
                sum += pre;
            }
            int suf = maxHeights[i];
            for (int j = i + 1; j < n; j++)
            {
                suf = min(suf, maxHeights[j]);
                sum += suf;
            }
            res = max(res, sum);
        }
        return res;
    }
};

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        vector<long long> prefix(n), suffix(n);
        stack<int> stack1, stack2;

        for (int i = 0; i < n; i++)
        {
            while (!stack1.empty() && maxHeights[stack1.top()] > maxHeights[i])
            {
                stack1.pop();
            }
            if (stack1.empty())
            {
                prefix[i] = (long long)(i + 1) * maxHeights[i];
            }
            else
            {
                prefix[i] = prefix[stack1.top()] + (long long)(i - stack1.top()) * maxHeights[i];
            }
            stack1.emplace(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack2.empty() && maxHeights[stack2.top()] > maxHeights[i])
            {
                stack2.pop();
            }
            if (stack2.empty())
            {
                suffix[i] = (long long)(n - i) * maxHeights[i];
            }
            else
            {
                suffix[i] = suffix[stack2.top()] + (long long)(stack2.top() - i) * maxHeights[i];
            }
            stack2.emplace(i);
            res = max(res, prefix[i] + suffix[i] - maxHeights[i]);
        }

        return res;
    }
};