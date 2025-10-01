#pragma once
using namespace std;
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
private:
    unordered_set<char> vowels = { 'A','E','I','O','U','a','e','i','o','u' };
public:
    string sortVowels(string s) {
        string vowel;
        for (char ch : s) {
            if (vowels.count(ch)) {
                vowel.push_back(ch);
            }
        }
        sort(vowel.begin(), vowel.end());
        
        int idx = 0;
        for (char& ch : s) {
            if (vowels.count(ch)) {
                ch = vowel[idx++];
            }
        }
        return s;
    }
};