#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto& c : address)
        {
            if (c == '.')
            {
                ans.append("[.]");
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};