#pragma once
using namespace std;
#include <string>
#include <stack>

/*
    �ļ�ϵͳ�ַ���ʵ��Ϊ������ǰ������Ľ��
    ������'\t'�ĸ�������ǰ�ڵ����ȣ����ڵ��ļ���֮�䶼��'\n'����
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        /*
            ����ջ���浱ǰ�Ѿ�����·���ĳ���
            ջ��Ԫ�صĸ�����Ϊ��ǰ·������ȣ�ջ��Ԫ�ؼ�Ϊ��ǰ·���ĳ���
        */
        stack<int> st;

        while (pos < n)
        {
            //��⵱ǰ�ļ������
            int depth = 1;
            while (pos < n && input[pos] == '\t')
            {
                pos++;
                depth++;
            }

            //ͳ�Ƶ�ǰ�ļ����ĳ���
            int len = 0;
            bool isFile = false;
            while (pos < n && input[pos] != '\n')
            {
                if (input[pos] == '.')
                {
                    isFile = true;
                }
                pos++;
                len++;
            }

            //�������з�
            pos++;

            /*
                �����ǰ�ڵ�����С�ڵ�ǰ·������ȣ��������ǰ�ڵ㲢����ջ���ڵ�ĺ��ӽڵ�
                �������������˳�����ʱ��Ҫ���л���ֱ��ջ���ڵ�Ϊ��ǰ�ڵ�ĸ��׽ڵ�
                �������ǰ�ڵ��·���볤��
            */
            while (st.size() >= depth)
            {
                st.pop();
            }

            if (!st.empty())
            {
                len += st.top() + 1; //1����·�����ӷ�'/'
            }
            if (isFile)
            {
                ans = max(ans, len);
            }
            else
            {
                st.emplace(len);
            }
        }
        return ans;
    }
};