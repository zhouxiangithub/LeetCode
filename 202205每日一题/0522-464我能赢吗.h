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
                //�ӵ�λ����λ����iλΪ1���ʾ����i�Ѿ���ʹ�ã�Ϊ0���ʾ����iδ��ʹ��
                if (((usedNumbers >> i) & 1) == 0) //��iλδ��ʹ�ã�������(i+1)δ��ʹ��
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