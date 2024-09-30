#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3, 0);
        int n = s.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        if (!(cnt[0] >= k && cnt[1] >= k && cnt[2] >= k)) {
            return -1;
        }

        int left = 0;
        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']--;
            while (left < right && (cnt[0] < k || cnt[1] < k || cnt[2] < k)) {
                cnt[s[left] - 'a']++;
                left++;
            }
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ans = min(ans, n - (right - left + 1));
            }
        }

        return ans;
    }
};