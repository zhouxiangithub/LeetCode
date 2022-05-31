#pragma once
using namespace std;
#include <vector>

/*
    ����һ������number��������һ���ֵ���������Ӧ�Ĺ����ǣ�
    (1)������number���渽��һ��0�����number*10<=n����ônumber*10����һ���ֵ���������
    (2)���number mod 10����9 �� number+1>n����ô˵��ĩβ����λ�Ѿ�������ɣ��˻���һλ������number = number/10��
       Ȼ������ж�ֱ��number mod 10������9 �� number+1<=nΪֹ����ônumber+1����һ���ֵ���������
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++)
        {
            ret[i] = number;
            if (number * 10 <= n)
            {
                number *= 10;
            }
            else
            {
                while (number % 10 == 9 || number + 1 > n)
                {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};