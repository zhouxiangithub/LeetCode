#pragma once
using namespace std;
#include <vector>
#include <string>
#include <functional>

/*
    定义函数dp(mask)来求解不同状态的最小贴纸数：
    输入是某个子序列mask，输出是拼出该子序列的最小贴纸数
    
    计算拼出mask所需的最小贴纸数时，需要选取最优的sticker让其贡献部分字符，未被sticker覆盖的其它字符left需要用动态规划继续计算。

    在动态规划时，子序列可以用一个二进制数来表示。
    从低位到高位，某位为0则表示在target中这一位不选取，为1则表示选取这一位，从而完成状态压缩的过程。
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