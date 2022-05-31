#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (auto& word : banned)
        {
            bannedSet.emplace(word);
        }

        int maxFreq = 0;
        unordered_map<string, int> freqs;
        string word = "";
        int len = paragraph.size();
        for (int i = 0; i <= len; i++) //"="用于最后一个单词的检验
        {
            if (i < len && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
            }
            else if (word.size() > 0)
            {
                if (!bannedSet.count(word))
                {
                    freqs[word]++;
                    maxFreq = max(maxFreq, freqs[word]);
                }
                word = "";
            }
        }

        for (auto& [word, freq] : freqs)
        {
            if (freq == maxFreq)
            {
                return word;
            }
        }

        return "";
    }
};