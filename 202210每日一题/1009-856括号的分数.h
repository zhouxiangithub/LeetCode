#pragma once
using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto c : s)
        {
            if (c == '(')
            {
                st.push(0);
            }
            else
            {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};