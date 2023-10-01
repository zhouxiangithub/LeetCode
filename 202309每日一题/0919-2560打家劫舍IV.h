#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        //�����ֵ����Сֵ����
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int count = 0;
            bool visited = false;
            for (int num : nums)
            {
                if (num <= mid && !visited) 
                {
                    count++; //�������Ϊmid������¿���͵ȡ���������Ŀ
                    visited = true;
                }
                else
                {
                    visited = false;
                }
            }
            if (count >= k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};