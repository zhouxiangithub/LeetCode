#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_set<string> seen;
        for (int i = 0; i < n; i++)
        {
            std::stringstream ss;
            ss << words[i][1] << words[i][0];
            string str = ss.str();
            if (seen.count(str))
            {
                ans++;
            }
            seen.insert(words[i]);
        }
        return ans;
    }
};