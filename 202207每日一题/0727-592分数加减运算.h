#pragma once
using namespace std;
#include <string>
#include <numeric>

/*
    x/y + a/b = (x*b+y*a)/(y*b)
*/
class Solution {
public:
    string fractionAddition(string expression) {
        long long up = 0, down = 1; //初始化分子分母
        int index = 0, n = expression.size();
        while (index < n)
        {
            //读取分子
            long long up1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+')
            {
                sign = expression[index] == '-' ? -1 : 1;
                index++;
            }
            while (index < n && isdigit(expression[index]))
            {
                up1 = up1 * 10 + expression[index] - '0';
                index++;
            }
            up1 = sign * up1;
            index++;

            //读取分母
            long long down1 = 0;
            while (index < n && isdigit(expression[index]))
            {
                down1 = down1 * 10 + expression[index] - '0';
                index++;
            }

            up = up * down1 + down * up1;
            down = down * down1;
        }
        if (up == 0)
        {
            return "0/1";
        }
        long long both = gcd(abs(up), down); //获取最大公约数
        return to_string(up / both) + "/" + to_string(down / both);
    }
};