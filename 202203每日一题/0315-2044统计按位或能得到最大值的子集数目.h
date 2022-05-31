#pragma once
using namespace std;
#include <vector>

/*
    ������һ������Ϊ n ���ص���������ʾ��ͬ���Ӽ����������Ķ����Ʊ�ʾ�У�n �����ص�ֵ�����˶����鲻ͬԪ�ص�ȡ�ᡣ
    �� i λֵΪ 1 ���ʾ���Ӽ�ѡȡ��ӦԪ�أ��� i λֵΪ 0 ���ʾ���Ӽ���ѡȡ��ӦԪ�ء�
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
    ����
    ����һ���������������� pos ��ʾ��ǰ�±꣬orVal ��ʾ��ǰ�±�֮ǰ��ĳ���Ӽ���λ��ֵ��
    �����Ϳ��Ա����Ӽ���λ���ֵ����Ϣ�������ݵ�ǰԪ��ѡ�������� orVal��
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