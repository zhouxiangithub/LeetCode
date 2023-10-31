#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h)
        {
            h++;
            i--;
        }
        return h;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), tol = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= n)
            {
                counter[n]++;
            }
            else
            {
                counter[citations[i]]++;
            }
        }
        for (int i = n; i >= 0; i--)
        {
            tol += counter[i];
            if (tol >= i)
            {
                return i;
            }
        }
        return 0;
    }
};