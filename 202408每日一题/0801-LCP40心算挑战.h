#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        int ans = 0;
        int sum = 0;
        int odd = -1, even = -1;
        int end = cards.size() - cnt;
        for (int i = cards.size() - 1; i >= end; i--) {
            sum += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            }
            else {
                even = cards[i];
            }
        }

        if (!(sum & 1)) {
            return sum;
        }

        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                if (even != -1) {
                    ans = max(ans, sum - even + cards[i]);
                    return ans;
                }
            }
            else {
                if (odd != -1) {
                    ans = max(ans, sum - odd + cards[i]);
                    return ans;
                }
            }
        }
        return ans;
    }
};