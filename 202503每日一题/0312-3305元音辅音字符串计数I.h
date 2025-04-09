#pragma once
using namespace std;
#include <string>
#include <set>
#include <unordered_map>

// ��������
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        set<char> vowels = { 'a','e','i','o','u' };
        // ÿ�� vowel ���ٳ���һ�������ٰ��� m �� consonant �����ַ�������Ŀ
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

                // i ׼��������
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