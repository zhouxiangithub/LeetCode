#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string word : wordlist) {
            words_perfect.insert(word);
            
            string wordlow;
            for (char c : word) {
                wordlow += tolower(c);
            }
            if (!words_low.count(wordlow)) {
                words_low[wordlow] = word;
            }

            string wordlowLike = likeVowel(wordlow);
            if (!words_like.count(wordlowLike)) {
                words_like[wordlowLike] = word;
            }
        }

        vector<string> res;
        for (string query : queries) {
            res.push_back(solve(query));
        }
        return res;
    }

private:
    unordered_set<string> words_perfect;
    unordered_map<string, string> words_low;
    unordered_map<string, string> words_like;

    string likeVowel(string word) {
        string res;
        for (char c : word) {
            res += isVowel(c) ? '*' : c;
        }
        return res;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string solve(string word) {
        if (words_perfect.count(word)) {
            return word;
        }

        string wordLow;
        for (char c : word) {
            wordLow += tolower(c);
        }
        if (words_low.count(wordLow)) {
            return words_low[wordLow];
        }

        string wordLike = likeVowel(wordLow);
        if (words_like.count(wordLike)) {
            return words_like[wordLike];
        }

        return "";
    }
};