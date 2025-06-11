#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
	struct State
	{
		int x;
		int y;
		int dis;
		State(int x, int y, int dis) :x(x), y(y), dis(dis) {};
		bool operator <(const State& rth)const {
			return rth.dis < dis;
		}
	};
public:
	const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
		int n = moveTime.size(), m = moveTime[0].size();
		vector<vector<int>> d(n, vector<int>(m, inf));
		vector<vector<int>> visited(n, vector<int>(m, 0));

		int dirs[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
		d[0][0] = 0;
		priority_queue<State> pq;
		pq.push(State(0, 0, 0));

		while (!pq.empty()) {
			State s = pq.top();
			pq.pop();
			if (visited[s.x][s.y]) {
				continue;
			}
			visited[s.x][s.y] = 1;
			for (int i = 0; i < 4; i++) {
				int nx = s.x + dirs[i][0];
				int ny = s.y + dirs[i][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
				if (dist < d[nx][ny]) {
					d[nx][ny] = dist;
					pq.push(State(nx, ny, dist));
				}
			}
		}
		return d[n - 1][m - 1];
    }
};