#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for (auto c : text)
        {
            count[c]++;
        }
        int res = 0;
        for (int i = 0; i < text.size();)
        {
            //�ҳ���ǰ������һ��[i,j)
            int j = i;
            while (j < text.size() && text[j] == text[i])
            {
                j++;
            }
            int cur_cnt = j - i;

            //�����һ�γ���С�ڸ��ַ����ֵ�����,����ǰ�������п�λ,��ʹ��cur_cnt+1���´�
            if (cur_cnt < count[text[i]] && (i > 0 || j < text.size()))
            {
                res = max(res, cur_cnt + 1);
            }

            //�ҵ���һ�κ�����֮���һ����ͬ�ַ�����һ��[j+1,k),�����������k=j+1
            int  k = j + 1;
            while (k < text.size() && text[k] == text[i])
            {
                k++;
            }
            res = max(res, min(k - i, count[text[i]]));
            i = j;
        }
        return res;
    }
};