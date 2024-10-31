#pragma once
using namespace std;
#include <unordered_map>

class Solution {
    unordered_map<int, int> memo;
    int dp(int k, int n) {
        if (memo.find(n * 100 + k) == memo.end()) {
            int ans;
            if (n == 0) {
                ans = 0;
            }
            else if (k == 1) {
                ans = n;
            }
            else {
                int left = 1, right = n;
                while (left + 1 < right) {
                    int mid = (right - left) / 2 + left;
                    int t1 = dp(k - 1, mid - 1); // ห้มห
                    int t2 = dp(k, n - mid); // รปห้

                    if (t1 < t2) {
                        left = mid;
                    }
                    else if (t1 > t2) {
                        right = mid;
                    }
                    else {
                        left = right = mid;
                    }
                }
                ans = 1 + min(max(dp(k - 1, left - 1), dp(k, n - left)), max(dp(k - 1, right - 1), dp(k, n - right)));
            }
            memo[n * 100 + k] = ans;
        }
        return memo[n * 100 + k];
    }
public:
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};