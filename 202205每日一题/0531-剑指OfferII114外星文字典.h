#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

/*
    以下两种情况不存在合法字母顺序：
    (1)字母之间的顺序关系存在由至少2个字母组成的环，如：["a","b","a"]
    (2)相邻两个单词满足后面的单词是前面的单词的前缀，且后面的单词的长度小于前面的单词的长度，如：["ab","a"]
*/
class Solution {
public:
    const int VISITING = 1, VISITED = 2;
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> states;
    bool valid = true;
    string order;
    int index;

    string alienOrder(vector<string>& words) {
        int length = words.size();
        for (string& word : words)
        {
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++)
            {
                char c = word[j];
                if (!edges.count(c))
                {
                    edges[c] = vector<char>();
                }
            }
        }
        for (int i = 1; i < length && valid; i++)
        {
            addEdge(words[i - 1], words[i]);
        }
        order = string(edges.size(), ' ');
        index = edges.size() - 1;
        for (auto [u, _] : edges)
        {
            if (!states.count(u))
            {
                dfs(u);
            }
        }
        if (!valid)
        {
            return "";
        }
        return order;
    }

    void addEdge(string before, string after)
    {
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length)
        {
            char c1 = before[index], c2 = after[index];
            if (c1 != c2)
            {
                edges[c1].emplace_back(c2);
                break;
            }
            index++;
        }
        if (index == length && length1 > length2)
        {
            valid = false;
        }
    }

    void dfs(char u)
    {
        states[u] = VISITING;
        for (char v : edges[u])
        {
            if (!states.count(v))
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (states[v] == VISITING) //环
            {
                valid = false;
                return;
            }
        }
        states[u] = VISITED;
        order[index] = u;
        index--;
    }
};