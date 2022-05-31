#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    ʵ�ʴ����У������ַ����н�������д��ĸ�����ǿ���ʹ��һ������Ϊ26������ά��ÿһ���ַ��ĳ��ִ�����
    ÿ���������ƣ����Ǹ�������λ�õ��ַ����ֵĴ�����Ȼ�������������ظ��ַ����ִ�������ʷ���ֵ��
    �������ʹ�ø����ֵ�������������ظ��ַ����������Դ��ж���ָ���Ƿ���Ҫ���Ƽ��ɡ�
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n)
        {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k)
            {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }

    int characterReplacement1(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int left = 0, right = 0, ans = 0;
        for (; right < n; right++)
        {
            num[s[right] - 'A']++;
            ans = max(ans, num[s[right] - 'A']);
            while (right - left + 1 - ans > k)
            {
                num[s[left++] - 'A']--;
            }
        }
        return right - left;
    }
};