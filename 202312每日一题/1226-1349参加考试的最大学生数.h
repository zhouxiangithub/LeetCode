#pragma once
using namespace std;
#include <vector>
#include <functional>
#include <map>

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        unordered_map<int, int> map;

        auto isSingleRowCompliant = [&](int status, int row)->bool {
            for (int j = 0; j < n; j++)
            {
                if ((status >> j) & 1)
                {
                    if (seats[row][j] == '#')
                    {
                        return false;
                    }
                    if (j > 0 && ((status >> (j - 1)) & 1))
                    {
                        return false;
                    }
                }
            }
            return true;
        };

        auto isCrossRowsCompliant = [&](int status, int upperRowStatus)->bool {
            for (int j = 0; j < n; j++)
            {
                if ((status >> j) & 1)
                {
                    if (j > 0 && ((upperRowStatus >> (j - 1)) & 1))
                    {
                        return false;
                    }
                    if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1))
                    {
                        return false;
                    }
                }
            }
            return true;
        };

        function<int(int, int)> dp = [&](int row, int status)->int {
            int key = (row << n) + status;
            if (!map.count(key))
            {
                if (!isSingleRowCompliant(status, row))
                {
                    map[key] = INT_MIN;
                    return INT_MIN;
                }
                int students = __builtin_popcount(status);
                if (row == 0)
                {
                    map[key] = students;
                    return students;
                }
                int mx = 0;
                for (int upperRowStatus = 0; upperRowStatus < (1 << n); upperRowStatus++)
                {
                    if (isCrossRowsCompliant(status, upperRowStatus))
                    {
                        mx = max(mx, dp(row - 1, upperRowStatus));
                    }
                }
                map[key] = mx + students;
            }
            return map[key];
        };

        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            ans = max(ans, dp(m - 1, i));
        }
        return ans;
    }
};