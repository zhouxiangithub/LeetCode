#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        int maxOdd = 1, minEven = s.size();
        for (const auto& [_, value] : cnt) {
            if (value & 1) {
                maxOdd = max(maxOdd, value);
            }
            else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};