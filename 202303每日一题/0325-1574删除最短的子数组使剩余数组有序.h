#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j])
        {
            j--;
        }
        if (j == 0)
        {
            return 0;
        }
        int res = j;
        for (int i = 0; i < n; i++)
        {
            while (j < n && arr[j] < arr[i])
            {
                j++;
            }
            res = min(res, j - i - 1); //(j-1)-(i+1)+1=j-i-1
            if (i + 1 < n && arr[i] > arr[i + 1])
            {
                break;
            }
        }
        return res;
    }
};