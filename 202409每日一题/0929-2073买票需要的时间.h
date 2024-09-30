#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            if (i <= k) {
                res += min(tickets[i], tickets[k]);
            }
            else {
                res += min(tickets[i], tickets[k] - 1);
            }
        }
        return res;
    }
};