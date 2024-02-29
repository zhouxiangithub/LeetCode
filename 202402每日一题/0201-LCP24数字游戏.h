#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<>> upper;
        long long mod = 1e9 + 7;
        long long lowerSum = 0, upperSum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i] - i; //预处理:问题转化为使得每个数相等的最少操作数
            if (lower.empty() || lower.top() >= x)
            {
                lowerSum += x;
                lower.push(x);
                if (lower.size() > upper.size() + 1)
                {
                    upperSum += lower.top();
                    upper.push(lower.top());
                    lowerSum -= lower.top();
                    lower.pop();
                }
            }
            else
            {
                upperSum += x;
                upper.push(x);
                if (upper.size() > lower.size())
                {
                    upperSum -= upper.top();
                    lowerSum += upper.top();
                    lower.push(upper.top());
                    upper.pop();
                }
            }
            //中位数
            if ((i + 1) % 2 == 0)
            {
                res[i] = (upperSum - lowerSum) % mod;
            }
            else
            {
                res[i] = (upperSum - lowerSum + lower.top()) % mod;
            }
        }
        return res;
    }
};