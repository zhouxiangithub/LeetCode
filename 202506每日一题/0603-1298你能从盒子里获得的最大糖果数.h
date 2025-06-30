#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> canOpen(n), hasBox(n), used(n);
        
        for (int i = 0; i < n; i++) {
            canOpen[i] = (status[i] == 1);
        }

        queue<int> q;
        int res = 0;
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (canOpen[box]) {
                q.push(box);
                used[box] = true;
                res += candies[box];
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            for (int key : keys[box]) {
                canOpen[key] = true;
                if (!used[key] && hasBox[key]) {
                    q.push(key);
                    used[key] = true;
                    res += candies[key];
                }
            }
            for (int bx : containedBoxes[box]) {
                hasBox[bx] = true;
                if (!used[bx] && canOpen[bx]) {
                    q.push(bx);
                    used[bx] = true;
                    res += candies[bx];
                }
            }
        }

        return res;
    }
};