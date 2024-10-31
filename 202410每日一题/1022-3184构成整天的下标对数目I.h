#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        for (int j = 0; j < hours.size(); j++) {
            for (int i = 0; i < j; i++) {
                if ((hours[i] + hours[j]) % 24 == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};