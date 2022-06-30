#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
    输入：nums = [3, 1, 4, 1, 5], k = 2
    输出：2
    解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
    尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
*/
class Solution {
public:
    //排序
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), j = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            //当i=0时，数对的两个元素值可以相同，但下标值必须不同
            //nums[i] != nums[i - 1]
            //尽管数组中有两个相同值 ，但我们只应返回不同的数对的数量
            if (i == 0 || nums[i] != nums[i - 1])
            {
                while (j < n && (nums[j] - nums[i] < k || j <= i))
                {
                    j++;
                }
                if (j < n && (nums[j] - nums[i] == k))
                {
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    //哈希表
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> res; //将数对较小值放入res中
        for (int num : nums)
        {
            if (visited.count(num - k))
            {
                res.emplace(num - k);
            }
            if (visited.count(num + k))
            {
                res.emplace(num);
            }
            visited.emplace(num);
        }
        return res.size();
    }
};