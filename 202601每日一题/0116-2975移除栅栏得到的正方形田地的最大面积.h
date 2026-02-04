#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
private:
    const static int MOD = 1e9 + 7;

    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto edge : hEdges) {
            if (vEdges.count(edge)) {
                res = max(res, edge);
            }
        }
        if (res == 0) {
            res = -1;
        }
        else {
            res = 1ll * res * res % MOD;
        }
        return res;
    }
};