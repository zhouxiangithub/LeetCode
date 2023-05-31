#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<int> get(string& word)
    {
        vector<int> diff(word.size() - 1);
        for (int i = 0; i < word.size() - 1; i++)
        {
            diff[i] = word[i + 1] - word[i];
        }
        return diff;
    }

    string oddString(vector<string>& words) {
        auto diff0 = get(words[0]);
        auto diff1 = get(words[1]);
        if (diff0 == diff1)
        {
            for (int i = 2; i < words.size(); i++)
            {
                if (diff0 != get(words[i]))
                {
                    return words[i];
                }
            }
        }
        auto diff2 = get(words[2]);
        return diff0 == diff2 ? words[1] : words[0];
    }
};