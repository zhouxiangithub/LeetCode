#pragma once
using namespace std;
#include <string>
#include <numeric>

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string res = s;
        s = s + s; //��s�ӳ�һ���Է����ȡ��ת����ַ���t
        int g = gcd(b, n);
        for (int i = 0; i < n; i += g) //ö������ת�Ĵ���
        {
            for (int j = 0; j < 10; j++) //ö�ٶ�t������λ���ۼӲ����Ĵ���
            {
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) //ö�ٶ�t��ż��λ���ۼӲ����Ĵ���
                {
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2)
                    {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2)
                    {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};