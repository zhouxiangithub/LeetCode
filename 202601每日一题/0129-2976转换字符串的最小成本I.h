#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX / 2));
        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            int ori = original[i] - 'a';
            int cha = changed[i] - 'a';
            graph[ori][cha] = min(graph[ori][cha], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int n = source.length();
        long long res = 0;
        for (int i = 0; i < source.length(); i++) {
            int src = source[i] - 'a';
            int tar = target[i] - 'a';
            if (graph[src][tar] == INT_MAX / 2) {
                return -1;
            }
            res += graph[src][tar];
        }

        return res;
    }
};