#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <unordered_map>

//从国王出发
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> queen_pos;
        for (const auto& queen : queens)
        {
            int x = queen[0], y = queen[1];
            queen_pos.insert(8 * x + y);
        }

        vector<vector<int>> ans;
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx == 0 && dy == 0)
                {
                    continue;
                }
                int kx = king[0] + dx, ky = king[1] + dy;
                while (kx >= 0 && kx < 8 && ky >= 0 && ky < 8)
                {
                    int pos = 8 * kx + ky;
                    if (queen_pos.count(pos))
                    {
                        ans.push_back({ kx,ky });
                        break;
                    }
                    kx += dx;
                    ky += dy;
                }
            }
        }

        return ans;
    }
};

//从皇后出发
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        auto sgn = [](int x)->int {
            return x > 0 ? 1 : (x == 0 ? 0 : -1);
        };

        unordered_map<int, pair<vector<int>, int>> candidates;
        int kx = king[0], ky = king[1];
        for (const auto& queen : queens)
        {
            int qx = queen[0], qy = queen[1];
            int x = qx - kx, y = qy - ky;
            if (x == 0 || y == 0 || abs(x) == abs(y))
            {
                int sgnx = sgn(x), sgny = sgn(y);
                int sgn = 10 * sgnx + sgny;
                if (!candidates.count(sgn) || (abs(x) + abs(y) < candidates[sgn].second))
                {
                    candidates[sgn] = { queen,abs(x) + abs(y) };
                }
            }
        }

        vector<vector<int>> ans;
        for (const auto& [_, value] : candidates)
        {
            ans.push_back(value.first);
        }
        return ans;
    }
};