#pragma once
using namespace std;
#include <vector>

/*
    可以用一个长度为 n 比特的整数来表示不同的子集，在整数的二进制表示中，n 个比特的值代表了对数组不同元素的取舍。
    第 i 位值为 1 则表示该子集选取对应元素，第 i 位值为 0 则表示该子集不选取对应元素。
*/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++)
        {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                if (((i >> j) & 1) == 1)
                {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue)
            {
                cnt++;
            }
            else if (cur > maxValue)
            {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};

/*
    回溯
    定义一个搜索函数，参数 pos 表示当前下标，orVal 表示当前下标之前的某个子集按位或值。
    这样就可以保存子集按位或的值的信息，并根据当前元素选择与否更新 orVal。
*/
class Solution {
private:
    vector<int> nums;
    int maxOr, cnt;
public:
    void dfs(int pos, int orVal)
    {
        if (pos == nums.size())
        {
            if (orVal > maxOr)
            {
                maxOr = orVal;
                cnt = 1;
            }
            else if (orVal == maxOr)
            {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal | nums[pos]);
        dfs(pos + 1, orVal);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }
};