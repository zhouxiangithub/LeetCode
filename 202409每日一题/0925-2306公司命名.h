#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // 按照首字母进行分组
        unordered_map<char, unordered_set<string>> names;
        for (const string& idea : ideas) {
            names[idea[0]].insert(idea.substr(1, idea.size() - 1));
        }

        // 交集
        auto getIntersectSize = [](const unordered_set<string>& a, const unordered_set<string>& b)->size_t {
            size_t ans = 0;
            for (const string& str : a) {
                if (b.count(str)) {
                    ans++;
                }
            }
            return ans;
        };

        long long ans = 0;
        for (auto&& [preA, setA] : names) {
            for (auto&& [preB, setB] : names) {
                if (preA == preB) {
                    continue;
                }
                int intersect = getIntersectSize(setA, setB);
                ans += static_cast<long long>(setA.size() - intersect) * (setB.size() - intersect);
            }
        }

        return ans;
    }
};