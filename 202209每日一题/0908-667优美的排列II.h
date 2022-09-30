#pragma once
using namespace std;
#include <vector>

//[1,2,...,n-k,n,n-k+1,n-1,n-k+2,...]
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> answer;
        for (int i = 1; i < n - k; i++)
        {
            answer.push_back(i);
        }
        for (int i = n - k, j = n; i <= j; i++, j--)
        {
            answer.push_back(i);
            if (i != j)
            {
                answer.push_back(j);
            }
        }
        return answer;
    }
};