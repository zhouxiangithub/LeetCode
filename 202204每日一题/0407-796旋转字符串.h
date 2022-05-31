#pragma once
using namespace std;
#include <string>

/*
    ���ַ���s��תiλ�����ַ���goal�е�ĳһλ�ַ�goal[j]��Ӧ
    ���ַ�goal[j]��ԭ�ַ���s�е��ַ�s[(i+j)%m]��Ӧ��m��ʾ�ַ���s�ĳ���
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size(), n = goal.size();
        if (m != n)
        {
            return false;
        }
        for (int i = 0; i < m; i++)
        {
            bool flag = true;
            //�ڹ̶�i������£��������е�j������Ӧ�ַ�����ͬ���򷵻�true�����򣬼�������������ѡ��i
            for (int j = 0; j < n; j++)
            {
                if (s[(i + j) % m] != goal[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
};