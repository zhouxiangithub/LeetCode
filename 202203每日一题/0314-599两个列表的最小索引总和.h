#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); i++)
        {
            index[list1[i]] = i;
        }

        vector<string> ret;
        int indexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
        {
            if (index.count(list2[i]) > 0)
            {
                int j = index[list2[i]];
                if (j > indexSum)
                {
                    continue;
                }
                if (i + j < indexSum)
                {
                    ret.clear();
                    ret.emplace_back(list2[i]);
                    indexSum = i + j;
                }
                else if (i + j == indexSum)
                {
                    ret.emplace_back(list2[i]);
                }
            }
        }

        return ret;
    }
};