#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
    x的二进制表示的非空子集y满足:y&x=y
*/
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(1 << n, INT_MAX); //已经分配过的元素集合的不兼容性之和
        dp[0] = 0;
        int group = n / k; //将数组划分到k个相同大小的子集中
        unordered_map<int, int> values;

        //预处理:筛选出所有大小符合条件的子集mask,并求出子集对应的不兼容性保存在哈希表中
        for (int mask = 1; mask < (1 << n); mask++)
        {
            if (__builtin_popcount(mask) != group)
            {
                continue;
            }
            int mmin = INT_MAX, mmax = INT_MIN;
            unordered_set<int> cur;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    if (cur.count(nums[i])) //同一个子集里面没有两个相同的元素
                    {
                        break;
                    }
                    cur.insert(nums[i]);
                    mmin = min(mmin, nums[i]);
                    mmax = max(mmax, nums[i]);
                }
            }
            if (cur.size() == group)
            {
                values[mask] = mmax - mmin;
            }
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] == INT_MAX)
            {
                continue;
            }
            unordered_map<int, int> seen;
            for (int i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) == 0)
                {
                    seen[nums[i]] = i;
                }
            }
            if (seen.size() < group)
            {
                continue;
            }
            int sub = 0; //对于每一个状态mask,求出还没有被分配的元素集合sub
            for (auto& pair : seen)
            {
                sub |= (1 << pair.second);
            }
            int nxt = sub;
            while (nxt)
            {
                //遍历sub的子集nxt,检查是否符合条件,作为下一组划分的元素集合
                if (values.count(nxt))
                {
                    dp[mask | nxt] = min(dp[mask | nxt], dp[mask] + values[nxt]);
                }
                nxt = (nxt - 1) & sub; //nxt是sub的一个非空子集
            }
        }

        return (dp[(1 << n) - 1] < INT_MAX) ? dp[(1 << n) - 1] : -1;
    }
};