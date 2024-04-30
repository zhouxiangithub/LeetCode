#pragma once
using namespace std;
#include <vector>

class TreeAncestor {
private:
    constexpr static int M = 16;
    vector<vector<int>> ancestors; // �ڵ�i�ĵ�2^j������
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>>(n, vector<int>(M, -1));
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < M; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1]; // ��ǰ�ڵ�ĵ�2^j�������ǵ�2^(j-1)�����ȵĵ�2^(j-1)������
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < M; j++) {
            if ((k >> j) & 1) {
                node = ancestors[node][j];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */