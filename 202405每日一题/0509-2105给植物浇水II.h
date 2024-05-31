#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0;
        int n = plants.size();
        int idxA = 0, idxB = n - 1;
        int leftA = capacityA, leftB = capacityB;
        while (idxA < idxB) {
            if (leftA < plants[idxA]) {
                res++;
                leftA = capacityA - plants[idxA];
            }
            else {
                leftA -= plants[idxA];
            }
            idxA++;
            if (leftB < plants[idxB]) {
                res++;
                leftB = capacityB - plants[idxB];
            }
            else {
                leftB -= plants[idxB];
            }
            idxB--;
        }
        if (idxA == idxB) {
            if (leftA >= leftB && leftA < plants[idxA]) {
                res++;
            }
            if (leftA < leftB && leftB < plants[idxB]) {
                res++;
            }
        }
        return res;
    }
};