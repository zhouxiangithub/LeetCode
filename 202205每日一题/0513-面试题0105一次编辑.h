#pragma once
using namespace std;
#include <string>

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if (n - m == 1)
        {
            return oneInsert(first, second);
        }
        else if (m - n == 1)
        {
            return oneInsert(second, first);
        }
        else if (m == n)
        {
            bool flag = false;
            for (int i = 0; i < m; i++)
            {
                if (first[i] != second[i])
                {
                    if (!flag)
                    {
                        flag = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool oneInsert(string shorter, string longer)
    {
        int len1 = shorter.size(), len2 = longer.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            if (shorter[idx1] == longer[idx2])
            {
                idx1++;
            }
            idx2++;
            if (idx2 - idx1 > 1)
            {
                return false;
            }
        }
        return true;
    }
};