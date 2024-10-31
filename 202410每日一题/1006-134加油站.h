#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int gasSum = 0, costSum = 0;
            int cnt = 0;
            while (cnt < n) {
                int next = (i + cnt) % n;
                gasSum += gas[next];
                costSum += cost[next];
                if (gasSum < costSum) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            }
            else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};