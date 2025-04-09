#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int largestVariance(string s) {
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < s.size(); i++) {
            pos[s[i]].push_back(i);
        }

        int ans = 0;
        for (auto&& [c0, pos0] : pos) {
            for (auto&& [c1, pos1] : pos) {
                if (c0 != c1) {
                    int i = 0, j = 0;
                    // f[i] 表示以 i 结尾的子数组的最大和, g[i] 表示以 i 结尾的并且一定包含 −1 的子数组的最大和
                    int f = 0, g = INT_MIN;
                    while (i < pos0.size() || j < pos1.size()) {
                        if (j == pos1.size() || (i < pos0.size() && pos0[i] < pos1[j])) {
                            tie(f, g) = tuple{ max(f,0) + 1, g + 1 };
                            i++;
                        }
                        else {
                            tie(f, g) = tuple{ max(f,0) - 1, max({f,g,0}) - 1 };
                            j++;
                        }
                        ans = max(ans, g);
                    }
                }
            }
        }
        return ans;
    }
};