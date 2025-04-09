#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

/**
* i 翻转的最大范围:[i-k+1, i+k-1]
* 数组在最左边(L=0, R=k-1)翻转的位置是:k-1-i
* 数组在最右边(L=n-k, R=n-1)翻转的位置是:2n-k-1-i
*/
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> ban(banned.begin(), banned.end());
        set<int> sets[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !ban.count(i)) {
                sets[i % 2].insert(i);
            }
        }
        vector ans(n, -1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mn = max(i - k + 1, k - 1 - i);
            int mx = min(i + k - 1, 2 * n - k - 1 - i);
            auto it = sets[mx % 2].lower_bound(mn);
            while (it != sets[mx % 2].end()) {
                if (*it > mx) {
                    break;
                }
                ans[*it] = ans[i] + 1;
                q.push(*it);
                it = sets[mn % 2].erase(it);
            }
        }
        return ans;
    }
};