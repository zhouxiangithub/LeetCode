#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //ö�ٵ�һ����
        for (int first = 0; first < n; first++)
        {
            //(1)��Ҫ����һ��ö�ٵ�����ͬ,�����ظ�
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            //����������Ӧ��ָ���ʼָ����������Ҷ�
            int third = n - 1;
            int target = -nums[first];
            //ö�ٵڶ�����
            for (int second = first + 1; second < n; second++)
            {
                //(2)��Ҫ����һ��ö�ٵ�����ͬ,�����ظ�
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                //��Ҫ��֤�ڶ�������ָ���ڵ���������ָ������
                while (second<third && nums[second] + nums[third]>target)
                {
                    third--;
                }
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({ nums[first],nums[second],nums[third] });
                }
            }
        }
        return ans;
    }
};