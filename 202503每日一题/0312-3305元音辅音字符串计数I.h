#pragma once
using namespace std;
#include <string>
#include <set>
#include <unordered_map>

// 滑动窗口
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        set<char> vowels = { 'a','e','i','o','u' };
        // 每个 vowel 至少出现一次且至少包含 m 个 consonant 的子字符串的数目
        auto count = [&](int m)->int {
            int res = 0;
            int n = word.size(), consonants = 0;
            unordered_map<char, int> occur;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && (occur.size() < vowels.size() || consonants < m)) {
                    if (vowels.count(word[j])) {
                        occur[word[j]]++;
                    }
                    else {
                        consonants++;
                    }
                    j++;
                }

                if (occur.size() == vowels.size() && consonants >= m) {
                    res += n - j + 1; // 1+[(n-1)-j+1]
                }

                // i 准备右移了
                if (vowels.count(word[i])) {
                    occur[word[i]]--;
                    if (0 == occur[word[i]]) {
                        occur.erase(word[i]);
                    }
                }
                else {
                    consonants--;
                }
            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};