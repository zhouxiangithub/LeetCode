#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26);
        for (int i = 0; i < order.size(); i++)
        {
            index[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            bool valid = false;
            for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++)
            {
                int prev = index[words[i - 1][j] - 'a'];
                int curr = index[words[i][j] - 'a'];
                if (prev < curr)
                {
                    valid = true;
                    break;
                }
                else if (prev > curr)
                {
                    return false;
                }
            }
            //ǰmin(words[i-1].size(), words[i].size())���ַ�һֱ������ȵ�
            if (!valid)
            {
                if (words[i - 1].size() > words[i].size())
                {
                    return false;
                }
            }
        }
        return true;
    }
};