#pragma once
using namespace std;
#include <string>
#include <vector>

struct Trie
{
    Trie* child[26];
    int id;

    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        id = -1;
    }
};

int add(Trie* node, const string& word, int& index) {
    for (char ch : word) {
        int i = ch - 'a';
        if (!node->child[i]) {
            node->child[i] = new Trie();
        }
        node = node->child[i];
    }
    if (node->id == -1) {
        node->id = ++index;
    }
    return node->id;
}

void update(long long& x, long long y) {
    if (x == -1 || y < x) {
        x = y;
    }
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.length(), m = original.size();
        Trie* root = new Trie();
        
        int p = -1;
        vector<vector<int>> graph(m * 2, vector<int>(m * 2, INT_MAX / 2));
        for (int i = 0; i < m * 2; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int ori = add(root, original[i], p);
            int cha = add(root, changed[i], p);
            graph[ori][cha] = min(graph[ori][cha], cost[i]);
        }

        for (int k = 0; k <= p; k++) {
            for (int i = 0; i <= p; i++) {
                for (int j = 0; j <= p; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        vector<long long> f(n, -1);
        for (int j = 0; j < n; j++) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long long base = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                update(f[j], base);
            }
            Trie* u = root;
            Trie* v = root;
            for (int i = j; i < n; i++) {
                u = u->child[source[i] - 'a'];
                v = v->child[target[i] - 'a'];
                if (!u || !v) {
                    break;
                }
                if (u->id != -1 && v->id != -1 && graph[u->id][v->id] != INT_MAX / 2) {
                    update(f[i], base + graph[u->id][v->id]);
                }
            }
        }
        return f[n - 1];
    }
};