#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            diff[i] = abs(s[i] - t[i]);
        }
        int maxLength = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += diff[right];
            while (sum > maxCost)
            {
                sum -= diff[left++];
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};