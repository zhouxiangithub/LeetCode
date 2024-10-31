#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int cnt = 0;
        int i = 0, last = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && skills[j] < skills[i] && cnt < k) {
                j++;
                cnt++;
            }
            if (cnt == k) {
                return i;
            }
            cnt = 1;
            last = i;
            i = j;
        }
        return last;
    }
};