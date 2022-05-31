#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_set;
        unordered_set<string> visited;
        char keys[4] = { 'A','C','G','T' };
        for (auto& str : bank)
        {
            bank_set.emplace(str);
        }
        if (start == end)
        {
            return 0;
        }
        if (!bank_set.count(end))
        {
            return -1;
        }
        queue<string> qu;
        qu.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                string curr = qu.front();
                qu.pop();
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (keys[k] != curr[j])
                        {
                            string next = curr;
                            next[j] = keys[k];
                            if (!visited.count(next) && bank_set.count(next))
                            {
                                if (next == end)
                                {
                                    return step;
                                }
                                qu.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};