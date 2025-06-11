#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        int res = 0;
        bool checkMid = false;
        for (const auto& [word, cnt] : freq) {
            string rev = string(1, word[1]) + word[0];
            if (rev == word) {
                if (cnt % 2 == 1) {
                    checkMid = true;
                }
                res += 2 * (cnt / 2 * 2);
            }
            else if (rev < word) { // ±ÜÃâÖØ¸´±éÀú
                res += 2 * 2 * min(freq.count(rev) ? freq[rev] : 0, freq[word]);
            }
        }
        if (checkMid) {
            res += 2;
        }
        return res;
    }
};