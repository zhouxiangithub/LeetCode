#pragma once
using namespace std;
#include <string>
#include <unordered_set>

class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o','u','A','E','I','O','U' };
        
        int n = sentence.size();
        int i = 0, index = 1;
        string ans;

        while (i < n)
        {
            int j = i;
            while (j < n && sentence[j] != ' ')
            {
                j++;
            }

            index++;
            if (index != 2)
            {
                ans += ' ';
            }
            if (vowels.count(sentence[i]))
            {
                ans += sentence.substr(i, j - i) + 'm' + string(index, 'a');
            }
            else
            {
                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(index, 'a');
            }

            i = j + 1;
        }

        return ans;
    }
};