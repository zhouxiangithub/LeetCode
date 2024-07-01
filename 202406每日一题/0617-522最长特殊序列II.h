#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto isSubSeq = [](const string& s, const string& t)->bool {
            int sIdx = 0, tIdx = 0;
            while (sIdx < s.size() && tIdx < t.size()) {
                if (s[sIdx] == t[tIdx]) {
                    sIdx++;
                }
                tIdx++;
            }
            return sIdx == s.size();
        };
        
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool check = true;
            for (int j = 0; j < n; j++) {
                if (j != i && isSubSeq(strs[i], strs[j])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans;
    }
};