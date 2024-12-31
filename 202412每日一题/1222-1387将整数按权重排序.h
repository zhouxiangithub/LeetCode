#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int getStepToOne(int n) {
        if (n == 1) {
            return 0;
        }
        else if (n & 1) {
            return getStepToOne(3 * n + 1) + 1;
        }
        else {
            return getStepToOne(n / 2) + 1;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), [&](int u, int v) {
            if (getStepToOne(u) != getStepToOne(v)) {
                return getStepToOne(u) < getStepToOne(v);
            }
            else {
                return u < v;
            }
            });
        return res[k - 1];
    }
};

class Solution {
public:
    unordered_map<int, int> mp;

    int getStepToOne(int n) {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        if (n == 1) {
            return mp[n] = 0;
        }
        if (n & 1) {
            return mp[n] = getStepToOne(3 * n + 1) + 1;
        }
        else {
            return mp[n] = getStepToOne(n / 2) + 1;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), [&](int u, int v) {
            if (getStepToOne(u) != getStepToOne(v)) {
                return getStepToOne(u) < getStepToOne(v);
            }
            else {
                return u < v;
            }
            });
        return res[k - 1];
    }
};