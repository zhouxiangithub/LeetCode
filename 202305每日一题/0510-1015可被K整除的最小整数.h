#pragma once
using namespace std;
#include <unordered_set>

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 1 % k, len = 1;
        unordered_set<int> set;
        set.insert(remainder);
        while (remainder != 0)
        {
            remainder = (remainder * 10 + 1) % k;
            len++;
            if (set.find(remainder) != set.end()) //��������ظ�����,������ѭ��,�޽�
            {
                return -1;
            }
            set.insert(remainder);
        }
        return len;
    }
};

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) //�ܱ�2��5����,˵��ĩβһ����Ϊ1,�޽�
        {
            return -1;
        }
        int remainder = 1 % k, len = 1;
        //��k��Ϊ2��5�ı���ʱ(��10����),����һ���н�
        //����n��mͬ��(n>m),��:k|(n-m),��n-m=11..1100..00,��k��10����,����:k|11..11,������һ���н�
        while (remainder != 0)
        {
            remainder = (remainder * 10 + 1) % k;
            len++;
        }
        return len;
    }
};