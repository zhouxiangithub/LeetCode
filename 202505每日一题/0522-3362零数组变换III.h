#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });

        priority_queue<int> pq;
        vector<int> arr(nums.size() + 1, 0);
        int count = 0;
        for (int i = 0, q = 0; i < nums.size(); i++) {
            count += arr[i];
            while (q < queries.size() && queries[q][0] <= i) {
                pq.push(queries[q][1]);
                q++;
            }
            while (count < nums[i] && !pq.empty() && pq.top() >= i) {
                count += 1;
                arr[pq.top() + 1] -= 1;
                pq.pop();
            }
            if (count < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};