#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0, ans = 0;
        for (int age : ages) {
            if (age < 15) {
                continue;
            }
            while (ages[left] <= 0.5 * age + 7) {
                left++;
            }
            while (right < n - 1 && ages[right + 1] <= age) {
                right++;
            }
            ans += (right - left + 1) - 1;
        }
        return ans;
    }
};