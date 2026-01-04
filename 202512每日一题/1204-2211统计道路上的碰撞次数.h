#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        int dir = -1; // <0:向左,0:停止,>0:向右数量
        for (char c : directions) {
            if (c == 'L') {
                if (dir >= 0) {
                    res += dir + 1; // 0:1,>0:dir-1+2
                    dir = 0;
                }
            }
            else if (c == 'S') {
                if (dir > 0) {
                    res += dir;
                }
                dir = 0;
            }
            else {
                if (dir > 0) {
                    dir++;
                }
                else {
                    dir = 1;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        int left = 0, right = n - 1;

        while (left < n && directions[left] == 'L') {
            left++;
        }

        while (right >= left && directions[right] == 'R') {
            right--;
        }
        
        int res = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
};