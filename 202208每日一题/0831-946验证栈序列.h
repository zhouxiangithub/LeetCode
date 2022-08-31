#pragma once
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};