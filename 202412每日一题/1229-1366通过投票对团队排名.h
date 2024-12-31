#pragma once
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using PairCharToVec = pair<char, vector<int>>;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        unordered_map<char, vector<int>> charToRanks;
        
        for (char c : votes[0]) { // ≥ı ºªØ
            charToRanks[c].resize(votes[0].size());
        }

        for (const string& vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                charToRanks[vote[i]][i]++;
            }
        }

        vector<PairCharToVec> result(charToRanks.begin(), charToRanks.end());
        sort(result.begin(), result.end(), [](const PairCharToVec& pcv1, const PairCharToVec& pcv2) {
            return pcv1.second > pcv2.second || (pcv1.second == pcv2.second && pcv1.first < pcv2.first);
            });

        string ans;
        for (auto& [ch, ranks] : result) {
            ans += ch;
        }
        return ans;
    }
};