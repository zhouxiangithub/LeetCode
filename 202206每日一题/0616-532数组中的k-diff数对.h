#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
    ���룺nums = [3, 1, 4, 1, 5], k = 2
    �����2
    ���ͣ������������� 2-diff ����, (1, 3) �� (3, 5)��
    ���������������� 1 ��������ֻӦ���ز�ͬ�����Ե�������
*/
class Solution {
public:
    //����
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), j = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            //��i=0ʱ�����Ե�����Ԫ��ֵ������ͬ�����±�ֵ���벻ͬ
            //nums[i] != nums[i - 1]
            //������������������ֵͬ ��������ֻӦ���ز�ͬ�����Ե�����
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
    //��ϣ��
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> res; //�����Խ�Сֵ����res��
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