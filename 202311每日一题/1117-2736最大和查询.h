#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedNums;
        vector<tuple<int, int, int>> sortedQueries;
        int nn = nums1.size(), qn = queries.size();
        
        for (int i = 0; i < nn; i++)
        {
            sortedNums.emplace_back(nums1[i], nums2[i]);
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<pair<int, int>>());

        for (int i = 0; i < qn; i++)
        {
            sortedQueries.emplace_back(i, queries[i][0], queries[i][1]);
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b) {
            return get<1>(a) > get<1>(b);
            });

        vector<pair<int, int>> stk;
        vector<int> answer(qn, -1);
        int j = 0;
        for (auto& [i, x, y] : sortedQueries)
        {
            while (j < nn && sortedNums[j].first >= x)
            {
                auto [num1, num2] = sortedNums[j];
                while (!stk.empty() && num1 + num2 >= stk.back().second)
                {
                    stk.pop_back();
                }
                if (stk.empty() || num2 > stk.back().first)
                {
                    stk.emplace_back(num2, num1 + num2);
                }
                j++;
            }
            int k = lower_bound(stk.begin(), stk.end(), make_pair(y, 0)) - stk.begin();
            if (k < stk.size())
            {
                answer[i] = stk[k].second;
            }
        }
        return answer;
    }
};