#pragma once
using namespace std;
#include <vector>

/*
    ����һ:
    һ���ֲ�����һ����һ��ȫ�ֵ���
    ���ֻ��Ҫ����Ƿ���ڷǾֲ�����,��: nums[i]>nums[j], j>i+1
    nums[i]>min(nums[i+2],nums[i+3],...,nums[n-1])

    ������:
    �����ڷǾֲ����õ����еĳ�ֱ�Ҫ����Ϊ;
    ����ÿ��Ԫ��nums[i]������:abs(nums[i]-i)<=1
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minR = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] > minR)
            {
                return false;
            }
            minR = min(minR, nums[i + 1]);
        }
        return true;
    }
};