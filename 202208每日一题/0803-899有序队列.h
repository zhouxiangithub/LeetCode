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
        else //k>2:һ�����Ծ����ƶ���s��������ַ���
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};