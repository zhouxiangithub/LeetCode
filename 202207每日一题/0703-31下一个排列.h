#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    我们希望找到一个大于当前序列的新序列，且变大的幅度尽可能的小
    (1)我们需要将左边的较小数与右边的较大数交换，以能够让当前排列变大，从而得到下一个排列。
    (2)同时我们要让这个较小数尽量靠右，而较大数尽可能小。
       当交换完后，较大数右边的数需要按照升序重新排列。
       这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。

    算法：对于长度为n的排列a
    (1)首先从后向前查找第一个顺序对(i,i+1)，满足a[i]<a[i+1]。
       这样较小数即为a[i]，此时[i+1,n)必然是下降序列。
    (2)如果找到了顺序对，那么在区间[i+1,n)中从后向前查找第一个元素j满足a[i]<a[j]。
       这样较大数即为a[j]。
    (3)交换a[i]与a[j]，此时可以证明区间[i+1,n)必为降序。
       我们可以直接反转区间[i+1,n)使其变为升序，而无需对该区间进行排序。
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};