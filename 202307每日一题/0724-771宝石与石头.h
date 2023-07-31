#pragma once
using namespace std;
#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        unordered_set<char> hset;
        for (int i = 0; i < jewels.length(); i++)
        {
            hset.insert(jewels[i]);
        }
        for (int j = 0; j < stones.length(); j++)
        {
            if (hset.count(stones[j]))
            {
                res++;
            }
        }
        return res;
    }
};