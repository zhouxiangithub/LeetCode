#pragma once
using namespace std;
#include <vector>
#include <queue>

using pii = pair<int, int>;

class Graph {
private:
    vector<vector<pii>> graph;

public:
    Graph(int n, vector<vector<int>>& edges) {
        graph = vector<vector<pii>>(n);
        for (auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(graph.size(), INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);
        while (!pq.empty())
        {
            auto [cost, curNode] = pq.top();
            pq.pop();
            if (curNode == node2)
            {
                return cost;
            }
            for (auto [nextNode, nextCost] : graph[curNode])
            {
                if (cost + nextCost < dist[nextNode])
                {
                    dist[nextNode] = cost + nextCost;
                    pq.emplace(cost + nextCost, nextNode);
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */