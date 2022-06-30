#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    //��������
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        
        //words�ĳ���Ϊm������ÿ�����ʵĳ���Ϊn��s�ĳ���Ϊls
        int m = words.size(), n = words[0].size(), ls = s.size();
        
        //n�δ��ڻ�����ɾȥǰi(0~n-1)����ĸ�󣬽�ʣ�µ���ĸ���л���
        for (int i = 0; i < n && i + m * n <= ls; i++)
        {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; j++)
            {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string& word : words)
            {
                if (--differ[word] == 0)
                {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n)
            {
                if (start != i)
                {
                    //�������ƣ��Ҳ������һ������
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0)
                    {
                        differ.erase(word);
                    }
                    //�������ƣ��������һ������
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0)
                    {
                        differ.erase(word);
                    }
                }
                if (differ.empty())
                {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};