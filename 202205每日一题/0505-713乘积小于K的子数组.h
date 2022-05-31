#pragma once
using namespace std;
#include <vector>

//��ʱ��
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = 1;
            for (int j = i; j < n; j++)
            {
                temp *= nums[j];
                if (temp >= k)
                {
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};

//�̶��Ҷ˵㣬�ƶ���˵㣬�����Ͳ���Ҫÿ�ζ�������0����ʼö��
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int temp = 1, left = 0;
        for (int right = 0; right < n; right++)
        {
            temp *= nums[right];
            while (left <= right && temp >= k)
            {
                temp /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};