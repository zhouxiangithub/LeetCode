#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0; //1<=n<=14
        vector<int> count(26); //保存字母表letters中各种字母的数目
        for (auto c : letters)
        {
            count[c - 'a']++;
        }
        //s表示单词子集,s的第k位为1代表单词子集s包含单词words[k]
        for (int s = 1; s < (1 << n); s++)
        {
            vector<int> wordCount(26); //统计子集s所有单词的字母数目
            for (int k = 0; k < n; k++)
            {
                if ((s & (1 << k)) == 0) //words[k]不在子集s中
                {
                    continue;
                }
                for (auto c : words[k])
                {
                    wordCount[c - 'a']++;
                }
            }
            bool flag = true;
            int sumScore = 0; //保存子集s的得分
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