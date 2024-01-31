#pragma once
using namespace std;
#include <numeric>
#include <stack>
#include <unordered_set>

//ax+by=z
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
        {
            return false;
        }
        if (jug1Capacity == 0 || jug2Capacity == 0)
        {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

using PII = pair<int, int>;
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty())
        {
            if (seen.count(stk.top()))
            {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain1, remain2] = stk.top();
            stk.pop();

            if (remain1 == targetCapacity || remain2 == targetCapacity || remain1 + remain2 == targetCapacity)
            {
                return true;
            }

            stk.emplace(jug1Capacity, remain2); //把1壶灌满
            stk.emplace(remain1, jug2Capacity); //把2壶灌满
            stk.emplace(0, remain2); //把1壶倒空
            stk.emplace(remain1, 0); //把2壶倒空
            stk.emplace(remain1 - min(remain1, jug2Capacity - remain2), remain2 + min(remain1, jug2Capacity - remain2)); //把1壶的水灌进2壶直至灌满或倒空
            stk.emplace(remain1 + min(remain2, jug1Capacity - remain1), remain2 - min(remain2, jug1Capacity - remain1)); //把2壶的水灌进1壶直至灌满或倒空
        }
        return false;
    }
};