#pragma once
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1)
        {
            string smallest = s;
            int n = s.size();
            for (int i = 1; i < n; i++)
            {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if (s < smallest)
                {
                    smallest = s;
                }
            }
            return smallest;
        }
        else //k>2:一定可以经过移动将s变成升序字符串
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};