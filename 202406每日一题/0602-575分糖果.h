#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};