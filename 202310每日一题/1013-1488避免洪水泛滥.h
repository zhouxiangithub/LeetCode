#pragma once
using namespace std;
#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < rains.size(); i++)
        {
            if (rains[i] == 0)
            {
                st.insert(i);
            }
            else
            {
                ans[i] = -1;
                auto it = mp.find(rains[i]);
                if (it != mp.end())
                {
                    auto it2 = st.lower_bound(it->second);
                    if (it2 == st.end())
                    {
                        return {};
                    }
                    ans[*it2] = rains[i];
                    st.erase(it2);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};