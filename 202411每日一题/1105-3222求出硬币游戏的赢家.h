#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string winningPlayer(int x, int y) {
        int ops = min(x, y / 4);
        return ops % 2 == 1 ? "Alice" : "Bob";
    }
};