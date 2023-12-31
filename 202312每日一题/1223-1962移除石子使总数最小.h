#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for (int i = 0; i < k; i++)
        {
            int pile = pq.top();
            pq.pop();
            pile -= pile / 2;
            pq.push(pile);
        }
        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};