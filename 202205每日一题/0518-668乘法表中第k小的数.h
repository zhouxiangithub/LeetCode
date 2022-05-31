#pragma once
using namespace std;

/*
    ��ڼ�С�ȼ������ж������ֲ�����x
    ���ڳ˷���ĵ�i�У�������x��������min(x/i,n)��
    ���������˷�������x�����ָ���Ϊ���ۼӺ�min(x/i,n), i=1,...,m
    i=1,2,...,x/n, x/n+1,...,m
*/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right)
        {
            int x = left + (right - left) / 2;
            int count = (x / n) * n;
            for (int i = x / n + 1; i <= m; i++)
            {
                count += x / i;
            }
            if (count >= k) //������count=kʱֱ�ӷ��ؽ������Ӧ�������֣����շ���������count=k����Сxֵ
            {
                right = x;
            }
            else
            {
                left = x + 1;
            }
        }
        return left;
    }
};