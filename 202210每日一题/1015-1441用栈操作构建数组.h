#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int prev = 0;
        for (int num : target)
        {
            // (num-1)-(prev+1)+1=num-prev-1
            for (int i = 0; i < num - prev - 1; i++)
            {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
            res.emplace_back("Push");
            prev = num;
        }
        return res;
    }
};