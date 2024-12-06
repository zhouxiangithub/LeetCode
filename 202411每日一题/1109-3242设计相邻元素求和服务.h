#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                valueToPos[grid[i][j]] = { i,j };
            }
        }
        this->grid = move(grid);
    }

    int adjacentSum(int value) {
        return getSum(value, 0);
    }

    int diagonalSum(int value) {
        return getSum(value, 1);
    }

    int getSum(int value, int idx) {
        auto [x, y] = valueToPos[value];
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[idx][d][0];
            int ny = y + dirs[idx][d][1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }
private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> valueToPos;
    static constexpr int dirs[2][4][2] = { {{0,1},{0,-1},{-1,0},{1,0}},{{-1,1},{1,1},{-1,-1},{1,-1}} };
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */