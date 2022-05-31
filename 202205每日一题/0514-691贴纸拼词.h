#pragma once
using namespace std;
#include <vector>
#include <string>
#include <functional>

/*
    ���庯��dp(mask)����ⲻͬ״̬����С��ֽ����
    ������ĳ��������mask�������ƴ���������е���С��ֽ��
    
    ����ƴ��mask�������С��ֽ��ʱ����Ҫѡȡ���ŵ�sticker���乱�ײ����ַ���δ��sticker���ǵ������ַ�left��Ҫ�ö�̬�滮�������㡣

    �ڶ�̬�滮ʱ�������п�����һ��������������ʾ��
    �ӵ�λ����λ��ĳλΪ0���ʾ��target����һλ��ѡȡ��Ϊ1���ʾѡȡ��һλ���Ӷ����״̬ѹ���Ĺ��̡�
*/
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        function<int(int)> helper = [&](int mask)
        {
            if (dp[mask] != -1)
            {
                return dp[mask];
            }
            dp[mask] = m + 1;
            for (auto& sticker : stickers)
            {
                int left = mask;
                vector<int> cnt(26);
                for (char& c : sticker)
                {
                    cnt[c - 'a']++;
                }
                for (int i = 0; i < m; i++)
                {
                    if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0)
                    {
                        cnt[target[i] - 'a']--;
                        left ^= 1 << i;
                    }
                }
                if (left < mask)
                {
                    dp[mask] = min(dp[mask], helper(left) + 1);
                }
            }
            return dp[mask];
        };
        int res = helper((1 << m) - 1);
        return res > m ? -1 : res;
    }
};