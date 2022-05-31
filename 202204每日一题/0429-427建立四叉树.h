#pragma once
using namespace std;
#include <vector>
#include <functional>

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    //递归
    Node* construct(vector<vector<int>>& grid) {
        function<Node* (int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1)
        {
            for (int i = r0; i < r1; i++)
            {
                for (int j = c0; j < c1; j++)
                {
                    if (grid[i][j] != grid[r0][c0]) //非叶子结点
                    {
                        return new Node(
                            true,
                            false,
                            dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                            dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                            dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                            dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
                        );
                    }
                }
            }
            //是叶子结点
            return new Node(grid[r0][c0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }

    //递归+二维前缀和优化
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + grid[i][j];
            }
        }

        auto getSum = [&](int r0, int c0, int r1, int c1)
        {
            return pre[r1][c1] - pre[r0][c1] - pre[r1][c0] + pre[r0][c0];
        };

        function<Node* (int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1)
        {
            int total = getSum(r0, c0, r1, c1);
            if (total == 0) //全0
            {
                return new Node(false, true);
            }
            if (total == (r1 - r0) * (c1 - c0)) //全1
            {
                return new Node(true, true);
            }
            return new Node(
                true,
                false,
                dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
            );
        };

        return dfs(0, 0, n, n);
    }
};