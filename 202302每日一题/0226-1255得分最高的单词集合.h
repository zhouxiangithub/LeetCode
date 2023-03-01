#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0; //1<=n<=14
        vector<int> count(26); //������ĸ��letters�и�����ĸ����Ŀ
        for (auto c : letters)
        {
            count[c - 'a']++;
        }
        //s��ʾ�����Ӽ�,s�ĵ�kλΪ1�������Ӽ�s��������words[k]
        for (int s = 1; s < (1 << n); s++)
        {
            vector<int> wordCount(26); //ͳ���Ӽ�s���е��ʵ���ĸ��Ŀ
            for (int k = 0; k < n; k++)
            {
                if ((s & (1 << k)) == 0) //words[k]�����Ӽ�s��
                {
                    continue;
                }
                for (auto c : words[k])
                {
                    wordCount[c - 'a']++;
                }
            }
            bool flag = true;
            int sumScore = 0; //�����Ӽ�s�ĵ÷�
            for (int i = 0; i < 26; i++)
            {
                sumScore += wordCount[i] * score[i];
                flag = flag && (wordCount[i] <= count[i]);
            }
            if (flag)
            {
                res = max(res, sumScore);
            }
        }
        return res;
    }
};