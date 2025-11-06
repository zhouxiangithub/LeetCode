#pragma once
using namespace std;
#include <vector>
#include <queue>
#include <functional>

struct Entry
{
    int i;
    int j;
    int val;
    bool operator<(const Entry& other) const {
        return other.val < this->val;
    }
    Entry(int i, int j, int val) : i(i), j(j), val(val) {}
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Entry, vector<Entry>, function<bool(const Entry& x, const Entry& other)>> pq(&Entry::operator<);
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push(Entry(0, 0, grid[0][0]));
        int res = 0;
        vector<pair<int, int>> directions{ {0,1},{0,-1},{1,0},{-1,0} };
        while (!pq.empty()) {
            Entry x = pq.top();
            pq.pop();

            if (1 == visited[x.i][x.j]) {
                continue;
            }
            visited[x.i][x.j] = 1;

            res = max(res, grid[x.i][x.j]);
            if (x.i == n - 1 && x.j == n - 1) {
                break;
            }

            for (const auto& [di, dj] : directions) {
                int ni = x.i + di, nj = x.j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (visited[ni][nj] == 0) {
                        pq.push(Entry(ni, nj, grid[ni][nj]));
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    bool check(vector<vector<int>>& grid, int threshold) {
        if (grid[0][0] > threshold) {
            return false;
        }
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        vector<pair<int, int>> directions{ {0,1},{0,-1},{1,0},{-1,0} };
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (const auto& [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (visited[ni][nj] == 0 && grid[ni][nj] <= threshold) {
                        q.push(make_pair(ni, nj));
                        visited[ni][nj] = 1;
                    }
                }
            }
        }
        return visited[n - 1][n - 1] == 1;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0, right = n * n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(grid, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};