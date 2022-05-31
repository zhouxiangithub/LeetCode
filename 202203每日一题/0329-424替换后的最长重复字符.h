#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    实际代码中，由于字符串中仅包含大写字母，我们可以使用一个长度为26的数组维护每一个字符的出现次数。
    每次区间右移，我们更新右移位置的字符出现的次数，然后尝试用它更新重复字符出现次数的历史最大值，
    最后我们使用该最大值计算出区间内最长重复字符的数量，以此判断左指针是否需要右移即可。
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n)
        {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k)
            {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }

    int characterReplacement1(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int left = 0, right = 0, ans = 0;
        for (; right < n; right++)
        {
            num[s[right] - 'A']++;
            ans = max(ans, num[s[right] - 'A']);
            while (right - left + 1 - ans > k)
            {
                num[s[left++] - 'A']--;
            }
        }
        return right - left;
    }
};