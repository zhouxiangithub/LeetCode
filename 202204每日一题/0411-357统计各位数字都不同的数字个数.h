#pragma once
using namespace std;

/*
    ������ϣ�
        �� n=2 ʱ��0<=x<100��x��ѡ������������ֹ��ɣ�ֻ��һλ����x������λ����x��
        ֻ��һλ����x��0~9����10�֣�
        ����λ����x�����������ѧ���м��㣺
            ��һλ��ѡ���� 9 �֣��� 1~9���ڶ�λ��ѡ��Ҳ�� 9 �֣��� 0~9 �г�ȥ��һλ��ѡ�񡣹���9*9=9*A(9,1)�֡�
        ���Ե� n=2 ʱ���ܹ��У�10+9*A(9,1) �֡�
        ͬ�������Ƶ������� n=3 ʱ���ܹ��У�10+9*A(9,1)+9*A(9,2) �֡� 
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 10;
        }
        int ans = 10, cur = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cur *= (9 - i);
            ans += 9 * cur;
        }
        return ans;
    }
};