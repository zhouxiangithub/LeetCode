#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = heights.size(), n = queries.size();
        vector<vector<pair<int, int>>> query(m);
        vector<int> ans(n);
        vector<int> st; // 从大到小

        for (int i = 0; i < n; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
                continue;
            }
            query[b].push_back(make_pair(i, heights[a]));
        }

        int top = -1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < query[i].size(); j++) {
                int q = query[i][j].first;
                int val = query[i][j].second;
                if (top == -1 || val >= heights[st[0]]) {
                    ans[q] = -1;
                    continue;
                }

                int left = 0, right = top;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (heights[st[mid]] > val) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                ans[q] = st[right];
            }

            while (top >= 0 && heights[i] >= heights[st[top]]) {
                st.pop_back();
                top--;
            }
            st.push_back(i);
            top++;
        }
        return ans;
    }
};