#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    static constexpr int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; i++)
        {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2)
            {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};