#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    // �ݹ� + ����
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || freq[pos].first > rest) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; i++) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; i++) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num : candidates) {
            if (freq.empty() || freq.back().first != num) {
                freq.emplace_back(num, 1);
            }
            else {
                freq.back().second++;
            }
        }
        dfs(0, target);
        return ans;
    }
};