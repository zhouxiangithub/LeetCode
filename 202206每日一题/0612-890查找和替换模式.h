#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool match(string& word, string& pattern)
    {
        unordered_map<char, char> mp;
        for (int i = 0; i < word.length(); i++)
        {
            char x = word[i], y = pattern[i];
            if (!mp.count(x))
            {
                mp[x] = y;
            }
            else if (mp[x] != y)
            {
                return false;
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto& word : words)
        {
            if (match(word, pattern) && match(pattern, word)) //Ë«Éä
            {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};