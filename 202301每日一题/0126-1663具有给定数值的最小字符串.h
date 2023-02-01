#pragma once
using namespace std;
#include <string>

/*
    ���赱ǰ��Ҫ�����i��λ�õ��ַ�c,��ʱʣ��n-i��λ����Ҫ����,����Щ�ַ���ֵ֮��Ϊk1
    ����: (n-i)*1 <= k1-value(c) <= (n-i)*26
    ==>   k1-(n-i)*26 <= value(c) <= k1-(n-i), value(c) >= 1
*/
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for (int i = 1; i <= n; i++)
        {
            int lower = max(1, k - (n - i) * 26);
            k -= lower;
            res.push_back('a' + lower - 1);
        }
        return res;
    }
};