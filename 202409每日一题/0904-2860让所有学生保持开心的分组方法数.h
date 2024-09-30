#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int countWays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // ����ȷ�����鷽����ȷ��
        for (int k = 0; k <= n; k++) {
            // ǰ k ��Ԫ�ص����ֵ�Ƿ�С�� k
            if (k > 0 && k <= nums[k - 1]) {
                continue;
            }
            //�� n-k ��Ԫ�ص���Сֵ�Ƿ���� k
            if (k < n && k >= nums[k]) {
                continue;
            }
            res++;
        }
        return res;
    }
};