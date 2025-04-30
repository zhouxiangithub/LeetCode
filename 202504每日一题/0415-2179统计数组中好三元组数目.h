#pragma once
using namespace std;
#include <vector>

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> value2Pos2(n), reversedIndexMapping(n);
        for (int i = 0; i < n; i++) {
            value2Pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[value2Pos2[nums1[i]]] = i; // pos2 -- pos1
        }

        FenwickTree tree(n);
        long long res = 0;
        for (int pos2 = 0; pos2 < n; pos2++) {
            int pos1 = reversedIndexMapping[pos2];
            int left = tree.query(pos1);
            tree.update(pos1, 1);
            int right = (n - pos1 - 1) - (pos2 - left);
            res += (long long)left * right;
        }
        return res;
    }
};