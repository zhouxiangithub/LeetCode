#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        //f[i]��ʾ��i�����֮����ۼ��������
        int f0 = -prices[0]; //���й�Ʊ
        int f1 = 0; //û�й�Ʊ,�䶳��
        int f2 = 0; //û�й�Ʊ,���䶳��
        for (int i = 1; i < n; i++)
        {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f2, f1);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1, f2);
    }
};