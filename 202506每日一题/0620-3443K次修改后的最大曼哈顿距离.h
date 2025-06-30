#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int maxDistance(string s, int k) {
        int res = 0;
        int latitude = 0, longitude = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i])
            {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
            }
            res = max(res, min(abs(latitude) + abs(longitude) + 2 * k, i + 1));
        }
        return res;
    }
};