#pragma once
using namespace std;
#include <string>
#include <stack>

/*
    文件系统字符串实际为树按照前序遍历的结果
    连续的'\t'的个数代表当前节点的深度，相邻的文件名之间都以'\n'隔开
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        /*
            利用栈保存当前已经遍历路径的长度
            栈中元素的个数即为当前路径的深度，栈顶元素即为当前路径的长度
        */
        stack<int> st;

        while (pos < n)
        {
            //检测当前文件的深度
            int depth = 1;
            while (pos < n && input[pos] == '\t')
            {
                pos++;
                depth++;
            }

            //统计当前文件名的长度
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

            //跳过换行符
            pos++;

            /*
                如果当前节点的深度小于当前路径的深度，则表明当前节点并不是栈顶节点的孩子节点
                按照先序遍历的顺序，则此时需要进行回退直到栈顶节点为当前节点的父亲节点
                再求出当前节点的路径与长度
            */
            while (st.size() >= depth)
            {
                st.pop();
            }

            if (!st.empty())
            {
                len += st.top() + 1; //1代表路径连接符'/'
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