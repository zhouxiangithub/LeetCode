#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
private:
    bool isVol(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int vol = 0, cons = 0;
        for (char ch : s) {
            if (isVol(ch)) {
                vol = max(vol, ++mp[ch]);
            }
            else {
                cons = max(cons, ++mp[ch]);
            }
        }
        return vol + cons;
    }
};