#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = s.size();
        //[0,i-1], [i,n-1]
        for (int i = 1; i < n; i++)
        {
            int score = 0;
            for (int j = 0; j < i; j++)
            {
                if (s[j] == '0')
                {
                    score++;
                }
            }
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')
                {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        return ans;
    }
};

//���α���
class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int n = s.size();

        //��ʼ��
        if (s[0] == '0') 
        {
            score++;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
            {
                score++;
            }
        }

        int ans = score;
        //�жϽ�s[i]����ʱscore�ı仯
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                score++;
            }
            else
            {
                score--;
            }
            ans = max(ans, score);
        }

        return ans;
    }
};