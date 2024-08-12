#pragma once
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int emailsCount = 0;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                if (!emailToIndex.count(account[i])) {
                    emailToIndex[account[i]] = emailsCount++;
                    emailToName[account[i]] = account[0];
                }
            }
        }

        UnionFind uf(emailsCount);
        for (auto& account : accounts) {
            int index1 = emailToIndex[account[1]];
            for (int i = 2; i < account.size(); i++) {
                int index2 = emailToIndex[account[i]];
                uf.unionSet(index1, index2);
            }
        }

        map<int, vector<string>> indexToEmails;
        for (auto& [email, index] : emailToIndex) {
            int idx = uf.find(index);
            vector<string>& ems = indexToEmails[idx];
            ems.emplace_back(email);
            indexToEmails[idx] = ems;
        }

        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.emplace_back(emailToName[emails[0]]);
            for (auto& email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }

        return merged;
    }
};