#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (boxes[j] == '1')
                {
                    sum += abs(j - i);
                }
            }
            res[i] = sum;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = boxes[0] - '0', right = 0, operations = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                right++;
                operations += i;
            }
        }
        vector<int> res(n);
        res[0] = operations;
        for (int i = 1; i < n; i++)
        {
            operations += left - right;
            if (boxes[i] == '1')
            {
                left++;
                right--;
            }
            res[i] = operations;
        }
        return res;
    }
};