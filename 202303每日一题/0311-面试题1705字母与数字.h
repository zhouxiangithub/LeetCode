#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> map; //(maxLength,startIndex)
        map[0] = -1;
        int sum = 0;
        int maxLength = 0;
        int startIndex = -1;
        int n = array.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(array[i][0]))
            {
                sum++;
            }
            else
            {
                sum--;
            }
            if (map.count(sum))
            {
                int firstIndex = map[sum];
                if (i - firstIndex > maxLength)
                {
                    maxLength = i - firstIndex;
                    startIndex = firstIndex + 1;
                }
            }
            else
            {
                map[sum] = i;
            }
        }
        if (maxLength == 0)
        {
            return {};
        }
        return vector<string>(array.begin() + startIndex, array.begin() + startIndex + maxLength);
    }
};