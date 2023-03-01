#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string alphabetBoardPath(string target) {
        int cx = 0, cy = 0;
        string res;
        for (char c : target)
        {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (cx > nx)
            {
                res.append(cx - nx, 'U');
            }
            if (cy > ny)
            {
                res.append(cy - ny, 'L');
            }
            if (cx < nx)
            {
                res.append(nx - cx, 'D');
            }
            if (cy < ny)
            {
                res.append(ny - cy, 'R');
            }
            res.push_back('!');
            cx = nx;
            cy = ny;
        }
        return res;
    }
};