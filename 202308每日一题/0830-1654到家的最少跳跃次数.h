#pragma once
using namespace std;
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tuple<int, int, int>> q; //(position, direction, step)
        unordered_set<int> visited;
        q.emplace(0, 1, 0); //1:+,-1:-
        visited.emplace(0);
        int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        while (!q.empty())
        {
            auto [position, direction, step] = q.front();
            q.pop();
            if (position == x)
            {
                return step;
            }

            int nextPosition = position + a;
            int nextDirection = 1;
            if (nextPosition >= lower && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition))
            {
                visited.emplace(nextPosition * nextDirection);
                q.emplace(nextPosition, nextDirection, step + 1);
            }

            if (direction == 1)
            {
                nextPosition = position - b;
                nextDirection = -1;
                if (nextPosition >= lower && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition))
                {
                    visited.emplace(nextPosition * nextDirection);
                    q.emplace(nextPosition, nextDirection, step + 1);
                }
            }
        }
        return -1;
    }
};