#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = 0, cnt = 0;
        while (right < k)
        {
            cnt += blocks[right] == 'W' ? 1 : 0;
            right++;
        }
        int res = cnt;
        //»¬¶¯´°¿Ú
        while (right < blocks.size())
        {
            cnt += blocks[right] == 'W' ? 1 : 0;
            cnt -= blocks[left] == 'W' ? 1 : 0;
            res = min(res, cnt);
            left++;
            right++;
        }
        return res;
    }
};