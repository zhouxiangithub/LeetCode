#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    string addSuffix(string name, int k)
    {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        vector<string> ans;
        for (const auto& name : names)
        {
            if (!map.count(name))
            {
                ans.emplace_back(name);
                map[name] = 1;
            }
            else
            {
                int k = map[name];
                while (map.count(addSuffix(name, k)))
                {
                    k++;
                }
                ans.emplace_back(addSuffix(name, k));
                map[name] = k + 1;
                map[addSuffix(name, k)] = 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        for (int i = 0; i < names.size(); i++)
        {
            string name = names[i];
            while (map.find(names[i]) != map.end())
            {
                names[i] = name + '(' + to_string(map[name]) + ')';
                map[name]++;
            }
            map[names[i]]++;
        }
        return names;
    }
};