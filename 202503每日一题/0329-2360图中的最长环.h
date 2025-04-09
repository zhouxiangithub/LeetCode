#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> label(n);
        int curLabel = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            if (label[i]) {
                continue;
            }
            int pos = i, startLabel = curLabel;
            while (pos != -1) {
                curLabel++;
                if (label[pos]) {
                    // 大于说明是在这一轮遍历中被遍历到的,小于是之前某轮(计算过了)
                    if (label[pos] > startLabel) {
                        ans = max(ans, curLabel - label[pos]);
                    }
                    break;
                }
                label[pos] = curLabel;
                pos = edges[pos];
            }
        }
        return ans;
    }
};