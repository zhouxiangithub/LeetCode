#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> direc{ {0,1},{1,0},{0,-1},{-1,0} };
        int direcIndex = 0;
        int x = 0, y = 0;
        for (char instruction : instructions)
        {
            if (instruction == 'G')
            {
                x += direc[direcIndex][0];
                y += direc[direcIndex][1];
            }
            else if (instruction == 'L')
            {
                direcIndex--;
            }
            else
            {
                direcIndex++;
            }
            direcIndex = (direcIndex + 4) % 4;
        }
        return direcIndex != 0 || (x == 0 && y == 0);
    }
};