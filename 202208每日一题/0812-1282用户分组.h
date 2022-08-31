#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups; //��С-���
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            int size = groupSizes[i];
            groups[size].emplace_back(i);
        }
        vector<vector<int>> groupList;
        for (auto& [size, people] : groups)
        {
            int groupCount = people.size() / size;
            for (int i = 0; i < groupCount; i++)
            {
                vector<int> group;
                int start = i * size;
                for (int j = 0; j < size; j++)
                {
                    group.emplace_back(people[start + j]);
                }
                groupList.emplace_back(group);
            }
        }
        return groupList;
    }
};