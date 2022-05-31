#pragma once
using namespace std;
#include <unordered_map>

class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
        {
            return false;
        }
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }

    bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal)
    {
        if (!memo.count(usedNumbers))
        {
            bool res = false;
            for (int i = 0; i < maxChoosableInteger; i++)
            {
                //从低位到高位，第i位为1则表示数字i已经被使用，为0则表示数字i未被使用
                if (((usedNumbers >> i) & 1) == 0) //第i位未被使用，即数字(i+1)未被使用
                {
                    if (i + 1 + currentTotal >= desiredTotal)
                    {
                        res = true;
                        break;
                    }
                    if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1))
                    {
                        res = true;
                        break;
                    }
                }
            }
            memo[usedNumbers] = res;
        }
        return memo[usedNumbers];
    }
};