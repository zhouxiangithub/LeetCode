#pragma once
using namespace std;
#include <string>

/*
    若字符串s旋转i位后与字符串goal中的某一位字符goal[j]对应
    则字符goal[j]与原字符串s中的字符s[(i+j)%m]对应，m表示字符串s的长度
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
            //在固定i的情况下，遍历所有的j，若对应字符都相同，则返回true，否则，继续遍历其它候选的i
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