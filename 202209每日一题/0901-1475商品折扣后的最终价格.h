#pragma once
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int dis = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    dis = prices[j];
                    break;
                }
            }
            ans.emplace_back(prices[i] - dis);
        }
        return ans;
    }
};

//µ¥µ÷Õ»£¬µ¹Ðò±éÀú
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
        }
        return ans;
    }
};