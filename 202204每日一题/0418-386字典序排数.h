#pragma once
using namespace std;
#include <vector>

/*
    对于一个整数number，它的下一个字典序整数对应的规则是：
    (1)尝试在number后面附加一个0，如果number*10<=n，那么number*10是下一个字典序整数；
    (2)如果number mod 10等于9 或 number+1>n，那么说明末尾的数位已经搜索完成，退回上一位，即：number = number/10，
       然后继续判断直到number mod 10不等于9 且 number+1<=n为止，那么number+1是下一个字典序整数。
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++)
        {
            ret[i] = number;
            if (number * 10 <= n)
            {
                number *= 10;
            }
            else
            {
                while (number % 10 == 9 || number + 1 > n)
                {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};