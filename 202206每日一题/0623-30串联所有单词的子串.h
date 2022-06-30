#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    //滑动窗口
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        
        //words的长度为m，其中每个单词的长度为n，s的长度为ls
        int m = words.size(), n = words[0].size(), ls = s.size();
        
        //n次窗口滑动，删去前i(0~n-1)个字母后，将剩下的字母进行划分
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
                    //窗口右移，右侧会增加一个单词
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0)
                    {
                        differ.erase(word);
                    }
                    //窗口右移，左侧会减少一个单词
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