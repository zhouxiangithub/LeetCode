#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> canNotLanSet;
        for (auto& friendship : friendships) {
            unordered_map<int, int> mLanMp;
            bool canLan = false;
            for (int language : languages[friendship[0] - 1]) { // A
                mLanMp[language] = 1;
            }
            for (int language : languages[friendship[1] - 1]) { // B
                if (mLanMp.count(language)) { // A 和 B 可以交流
                    canLan = true;
                    break;
                }
            }
            if (!canLan) { // A 和 B 无法交流
                canNotLanSet.insert(friendship[0]);
                canNotLanSet.insert(friendship[1]);
            }
        }

        int maxCnt = 0; // 无法交流人集合里会共同语言的最大值
        vector<int> cnt(n + 1, 0);
        for (auto& friendship : canNotLanSet) {
            for (int language : languages[friendship - 1]) {
                cnt[language]++;
                maxCnt = max(maxCnt, cnt[language]);
            }
        }
        return canNotLanSet.size() - maxCnt;
    }
};