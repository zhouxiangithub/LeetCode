#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string solveEquation(string equation) {
        int factor = 0, val = 0;
        int index = 0, n = equation.size(), sign1 = 1; // ��ʽ���Ĭ��ϵ��Ϊ��
        while (index < n) 
        {
            if (equation[index] == '=') {
                sign1 = -1; // ��ʽ�ұ�Ĭ��ϵ��Ϊ��
                index++;
                continue;
            }

            int sign2 = sign1, number = 0;
            bool valid = false; // ��¼ number �Ƿ���Ч
            if (equation[index] == '-' || equation[index] == '+') // ȥ��ǰ��ķ���
            {
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }
            while (index < n && isdigit(equation[index])) 
            {
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }

            if (index < n && equation[index] == 'x') // ����
            { 
                factor += valid ? sign2 * number : sign2;
                index++;
            }
            else // ��ֵ
            { 
                val += sign2 * number;
            }
        }

        if (factor == 0) 
        {
            return val == 0 ? "Infinite solutions" : "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};