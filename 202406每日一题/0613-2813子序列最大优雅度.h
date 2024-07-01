#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [&](const vector<int>& item1, const vector<int>& item2)->bool {
            return item1[0] > item2[0]; });
        long long res = 0, profit = 0;
        unordered_set<int> categorySet;
        stack<int> st;
        for (int i = 0; i < items.size(); i++) {
            if (i < k) {
                profit += items[i][0];
                if (categorySet.count(items[i][1]) == 0) {
                    categorySet.insert(items[i][1]);
                }
                else
                {
                    st.push(items[i][0]);
                }
            }
            else if (categorySet.count(items[i][1]) == 0 && !st.empty()) {
                profit += items[i][0] - st.top();
                st.pop();
                categorySet.insert(items[i][1]);
            }
            res = max(res, (long long)(profit + categorySet.size() * categorySet.size()));
        }
        return res;
    }
};