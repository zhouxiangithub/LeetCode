#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            for (int j = 0; j < word.size(); j++)
            {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((masks[i] & masks[j]) == 0)
                {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> map;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            int mask = 0;
            string word = words[i];
            for (int j = 0; j < word.size(); j++)
            {
                mask |= 1 << (word[j] - 'a');
            }
            auto it = map.find(mask);
            if (it != map.end())
            {
                if (word.size() > it->second)
                {
                    map[mask] = word.size();
                }
            }
            else
            {
                map[mask] = word.size();
            }
        }
        int maxProd = 0;
        for (auto [mask1, _] : map)
        {
            for (auto [mask2, _] : map)
            {
                if ((mask1 & mask2) == 0)
                {
                    maxProd = max(maxProd, map[mask1] * map[mask2]);
                }
            }
        }
        return maxProd;
    }
};