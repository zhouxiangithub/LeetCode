#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int left = 0, right = 0;
        while (right < n)
        {
            while (right < n && title[right] != ' ')
            {
                right++;
            }
            if (right - left > 2)
            {
                title[left++] = toupper(title[left]);
            }
            while (left < right)
            {
                title[left++] = tolower(title[left]);
            }
            left = ++right;
        }
        return title;
    }
};