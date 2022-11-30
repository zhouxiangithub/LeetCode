#pragma once
using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = expression.size();
        for (int i = 0; i < n; i++)
        {
            char c = expression[i];
            if (c == ',')
            {
                continue;
            }
            else if (c != ')')
            {
                stk.push(c);
            }
            else
            {
                int tNum = 0, fNum = 0;
                while (stk.top() != '(')
                {
                    char val = stk.top();
                    stk.pop();
                    if (val == 't')
                    {
                        tNum++;
                    }
                    else
                    {
                        fNum++;
                    }
                }
                stk.pop(); //'('
                char op = stk.top();
                stk.pop(); //op
                switch (op)
                {
                case '!':
                    stk.push(fNum == 1 ? 't' : 'f');
                    break;
                case '&':
                    stk.push(fNum == 0 ? 't' : 'f');
                    break;
                case '|':
                    stk.push(tNum > 0 ? 't' : 'f');
                    break;
                default:
                    break;
                }
            }
        }
        return stk.top() == 't';
    }
};