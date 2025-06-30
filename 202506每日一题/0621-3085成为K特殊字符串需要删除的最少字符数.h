#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;
        for (auto& ch : word) {
            cnt[ch]++;
        }
        int res = word.size();
        for (auto& [_, num1] : cnt) {
            int del = 0;
            for (auto& [_, num2] : cnt) {
                if (num1 > num2) {
                    del += num2;
                }
                else if (num1 + k < num2) {
                    del += (num2 - (num1 + k));
                }
            }
            res = min(res, del);
        }
        return res;
    }
};