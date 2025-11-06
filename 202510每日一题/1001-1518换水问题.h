#pragma once
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, bottle = numBottles;
        while (bottle >= numExchange) {
            bottle -= numExchange;
            res++;
            bottle++;
        }
        return res;
    }
};