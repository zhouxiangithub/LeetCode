#pragma once
using namespace std;
#include <vector>
#include <queue>

typedef pair<int, int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = apples.size();
        int i = 0;
        while (i < n) {
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            int expDay = i + days[i];
            int count = apples[i];
            if (count > 0) {
                pq.emplace(expDay, count);
            }
            if (!pq.empty()) {
                pii cur = pq.top();
                pq.pop();
                cur.second--;
                if (cur.second != 0) {
                    pq.emplace(cur.first, cur.second);
                }
                ans++;
            }
            i++;
        }
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            if (pq.empty()) {
                break;
            }
            pii cur = pq.top();
            pq.pop();
            int num = min(cur.first - i, cur.second);
            ans += num;
            i += num;
        }
        return ans;
    }
};