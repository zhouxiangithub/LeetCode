#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        int sumM = 0, sumN = 0;
        for (int i = 0; i < m; i++)
        {
            sumM += rolls[i];
        }
        sumN = sum - sumM;
        if (sumN < n || sumN>6 * n)
        {
            return {};
        }
        int quo = sumN / n, rem = sumN % n;
        vector<int> res(n);
        if (quo != 6)
        {
            int sixQuo = rem / (6 - quo), sixRem = rem % (6 - quo);
            if (sixQuo > 0)
            {
                for (int i = 0; i < sixQuo; i++)
                {
                    res[i] = 6;
                }
                res[sixQuo] = quo + sixRem;
                for (int j = sixQuo + 1; j < n; j++)
                {
                    res[j] = quo;
                }
            }
            else
            {
                res[0] = quo + sixRem;
                for (int i = 1; i < n; i++)
                {
                    res[i] = quo;
                }
            }
        }
        else
        {
            if (rem)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    res[i] = quo;
                }
                res[n - 1] = rem;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    res[i] = quo;
                }
            }
        }
        return res;
    }

    vector<int> missingRolls1(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        int sumM = 0, sumN = 0;
        for (int i = 0; i < m; i++)
        {
            sumM += rolls[i];
        }
        sumN = sum - sumM;
        if (sumN < n || sumN>6 * n)
        {
            return {};
        }
        int quo = sumN / n, rem = sumN % n;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = quo + (i < rem ? 1 : 0);
        }
        return res;
    }
};