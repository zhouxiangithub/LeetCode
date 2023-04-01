#pragma once
using namespace std;
#include <vector>
#include <numeric>

/*
*   a e i o u
*   0 1 2 3 4
    dp[i][j]表示长度为i+1,以j结尾的按字典序排列的字符串数量
    显然dp[0][j]=1
*/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

/*
    a e i o u
    0=Ia <= Ie <= Ii <= Io <= Iu <=n
    0=Ia <= Ie < Ii+1 < Io+1+1 < Iu+1+1+1 <=n+1+1+1=n+3
 ==>0 <= Ie < Ii < Io < Iu <=n+3
    组合数: C(4,n+4)
*/
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};