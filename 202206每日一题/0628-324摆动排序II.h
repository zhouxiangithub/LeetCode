#pragma once
using namespace std;
#include <vector>
#include <algorithm>

/*
    ����������Ԫ�ص���ĿΪn������������ͬԪ�ص���Ŀ��಻����: x=(n+1)/2
    ��֤����֤��������ͬԪ����Ŀ���ڸ�ֵ���������ͬ��Ԫ�����ڣ��⽫���°ڶ������޷����

    ���Ƚ����鰴�մ�С����������������nums[i]������nums[i+x]����һ����: nums[i]<nums[i+x]
    ��ˣ����ǿ��Եõ���nums[0]<nums[x], nums[1]<nums[x+1],..., nums[i]<nums[i+x]

    ��nΪż��ʱ�����Խ�nums[i+x]���뵽nums[i-1]��nums[i]֮�䣺
    nums[x], nums[0], nums[x+1], nums[1],..., nums[n-2-x], nums[n-1], nums[n-1-x]
    Ȼ���������н��з�ת��
    nums[n-1-x], nums[n-1], nums[n-2-x],..., nums[1], nums[x+1], nums[0], nums[x]

    ��nΪ����ʱ������֤������֤����������i>0ʱ��nums[i]<nums[i+x-1]
    ���Խ�nums[i+x]���뵽nums[i]��nums[i+1]֮�䣺
    nums[0], nums[x], nums[1],..., nums[n-1-x], nums[n-1], nums[n-x]
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
        {
            nums[i] = arr[j];
            if (i + 1 < n)
            {
                nums[i + 1] = arr[k];
            }
        }
    }
};