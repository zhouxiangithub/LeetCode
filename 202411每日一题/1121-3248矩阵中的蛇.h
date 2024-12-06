#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (const string& command : commands) {
            if (command == "UP") {
                ans -= n;
            }
            else if (command == "DOWN") {
                ans += n;
            }
            else if (command == "LEFT") {
                ans--;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};