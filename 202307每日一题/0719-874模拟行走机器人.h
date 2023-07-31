#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //(初始北)左/前/右/后
        int px = 0, py = 0, d = 1;
        unordered_set<int> hset;
        for (auto& obstacle : obstacles)
        {
            hset.emplace(obstacle[0] * 60001 + obstacle[1]);
        }
        int res = 0;
        for (int command : commands)
        {
            if (command < 0)
            {
                d += command == -1 ? 1 : -1;
                d %= 4;
                if (d < 0)
                {
                    d += 4;
                }
            }
            else
            {
                for (int i = 0; i < command; i++)
                {
                    if (hset.count((px + dirs[d][0]) * 60001 + py + dirs[d][1]))
                    {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};