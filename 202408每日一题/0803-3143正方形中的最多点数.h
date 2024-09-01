#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> firMin(26, 1000000001);
        int secMin = 1000000001;
        for (int i = 0; i < s.length(); i++) {
            int x = points[i][0], y = points[i][1], j = s[i] - 'a';
            int d = max(abs(x), abs(y));
            if (d < firMin[j]) {
                secMin = min(secMin, firMin[j]);
                firMin[j] = d;
            }
            else if (d < secMin) {
                secMin = d;
            }
        }
        int res = 0;
        for (int fm : firMin) {
            if (fm < secMin) {
                res++;
            }
        }
        return res;
    }
};