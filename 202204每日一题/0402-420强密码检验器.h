#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool has_lower = false, has_upper = false, has_digit = false;
        for (char ch : password)
        {
            if (islower(ch))
            {
                has_lower = true;
            }
            else if (isupper(ch))
            {
                has_upper = true;
            }
            else if (isdigit(ch))
            {
                has_digit = true;
            }
        }
        int categories = has_lower + has_upper + has_digit; //�ַ����а���Сд��ĸ����д��ĸ�����ֵ�����

        //�޸Ĳ��������롢ɾ�����滻
        if (n < 6)
        {
            //���ַ�������С��6ʱ��ͬʱҪ����ǿ�����ַ����������ٰ��������ַ�������õĲ����ǲ��루�����ͬʱ���������ַ����ĳ��ȣ�
            return max(6 - n, 3 - categories);
        }
        else if (n <= 20)
        {
            /*
                ���ַ���������ǿ���볤����������õĲ������滻��������������k����ͬ���ַ�
                �滻�����Ĵ���Ϊ�����е�(k/3)֮����(3 - categories)�еĽϴ�ֵ
            */
            int replace = 0;
            int cnt = 0;
            char cur = '#';
            for (char ch : password)
            {
                if (ch == cur)
                {
                    cnt++;
                }
                else
                {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3; //�������ַ���������ԭ�ַ��������
            return max(replace, 3 - categories);
        }
        else
        {
            /*
                ���ַ������ȴ���20ʱ��Ϊ����ǿ���볤����������Ҫ����ɾ�����������ٳ��ȣ�
                �����ַ�����������Ҫ��󣬽�����������Ҫ�����滻����������ʱ����������3��������ͬ���ַ���

                �滻�����Ĵ���Ϊ�����е�(k/3)֮��
                ɾ�������Ĵ���Ϊ��(n-20)

                ɾ����������ʹ���滻������������1��
                ���k%3=0����ôɾ��1���ַ���k/3��ֵ�����1�����ÿɾ��3���ַ���k/3��ֵ���ټ���1��
                ���k%3=1����ôɾ��2���ַ���k/3��ֵ�����1�����ÿɾ��3���ַ���k/3��ֵ���ټ���1��
                ���k%3=2����ôÿɾ��3���ַ���k/3��ֵ�����1��

                ��ˣ�ɾ����˳���ǣ�
                (1)������k%3=0��������ͬ�ַ�����ɾ��1���ַ���
                (2)������k%3=1��������ͬ�ַ�����ɾ��2���ַ���
                (3)ɾ��3���ַ���
            */
            int replace = 0, remove = n - 20;
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';
            for (char ch : password)
            {
                if (ch == cur)
                {
                    cnt++;
                }
                else
                {
                    if (remove > 0 && cnt >= 3)
                    {
                        if (cnt % 3 == 0)
                        {
                            remove--;
                            replace--;
                        }
                        else if (cnt % 3 == 1)
                        {
                            rm2++;
                        }
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }

            //�������ַ���������ԭ�ַ��������
            if (remove > 0 && cnt >= 3)
            {
                if (cnt % 3 == 0)
                {
                    remove--;
                    replace--;
                }
                else if (cnt % 3 == 1)
                {
                    rm2++;
                }
            }
            replace += cnt / 3;

            //k%3=0���������Ѿ����۹��ˣ�����������k%3=1�������(2)������k%3=1��������ͬ�ַ�����ɾ��2���ַ���
            int use2 = min(replace, min(rm2, remove / 2)); //ɾ��2���ַ��Ĵ���
            replace -= use2;
            remove -= use2 * 2;

            //����������k%3=2�������(3)ɾ��3���ַ���
            int use3 = min(replace, remove / 3);
            replace -= use3;
            remove -= use3 * 3;

            return (n - 20) + max(replace, 3 - categories);
        }
    }
};