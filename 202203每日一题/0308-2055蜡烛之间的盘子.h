#pragma once
using namespace std;
#include <vector>
#include <string>

//超时
class Solution {
public:
    int platesBC(string s, vector<int>& query)
    {
        int res = 0;
        int left = query[0], right = query[1];
        while (left < right)
        {
            if (s[left] == '|' && s[right] == '|')
            {
                break;
            }
            if (s[left] == '|')
            {
                right--;
            }
            if (s[right] == '|')
            {
                left++;
            }
        }
        if (left < right)
        {
            for (int i = left + 1; i < right; i++)
            {
                if (s[i] == '*')
                {
                    res++;
                }
            }
        }
        return res;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int size = queries.size();
        vector<int> ans;
        for (int i = 0; i < size; i++)
        {
            ans.emplace_back(platesBC(s, queries[i]));
        }
        return ans;
    }
};

/*
    预处理 + 前缀和
    i      0  1  2  3  4  5  6  7  8  9
           *  *  |  *  *  |  *  *  *  |
    left  -1 -1  2  2  2  5  5  5  5  9
    right  2  2  2  5  5  5  9  9  9  9
*/
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                sum++;
            }
            preSum[i] = sum;
        }

        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++)
        {
            if (s[i] == '|')
            {
                l = i;
            }
            left[i] = l;
        }

        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                r = i;
            }
            right[i] = r;
        }

        /*
            区间左端点lefti右侧的第一个蜡烛即为区间最左侧的蜡烛
            区间右端点righti左侧的第一个蜡烛即为区间最右侧的蜡烛
        */
        vector<int> ans;
        for (auto& query : queries)
        {
            int x = right[query[0]], y = left[query[1]];
            ans.emplace_back((x == -1 || y == -1 || x >= y) ? 0 : (preSum[y] - preSum[x]));
        }
        return ans;
    }
};