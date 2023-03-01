#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> suitsSet;
        for (char suit : suits)
        {
            suitsSet.emplace(suit);
        }
        if (suitsSet.size() == 1)
        {
            return "Flush";
        }
        unordered_map<int, int> ranksMap;
        for (int rank : ranks)
        {
            ranksMap[rank]++;
        }
        if (ranksMap.size() == 5)
        {
            return "High Card";
        }
        for (auto [_, val] : ranksMap)
        {
            if (val > 2)
            {
                return "Three of a Kind";
            }
        }
        return "Pair";
    }
};