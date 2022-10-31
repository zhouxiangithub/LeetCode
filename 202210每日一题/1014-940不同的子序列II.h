#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    记fi表示以si为最后一个字符的子序列的数目
    (1)如果子序列中只有si这一个字符，那么有一种方案；
    (2)如果子序列中至少有两个字符，状态转移方程，倒数第二个字符可以是s0,s1,...,s[i-1]中的某一个，即：
    fi = f0 + f1 + ... + f[i-1], 为了避免重复计算，对于每一种字符，我们只需要找到其最后一次出现的位置，
    并且在位置i之前，并将对应的f值累加进fi即可。

*/
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> last(26, -1);

        int n = s.length();
        vector<int> f(n, 1); //初始化每个fi都为1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (last[j] != -1)
                {
                    f[i] = (f[i] + f[last[j]]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (last[i] != -1)
            {
                ans = (ans + f[last[i]]) % mod;
            }
        }
        return ans;
    }
private:
    static constexpr int mod = 1000000007;
};