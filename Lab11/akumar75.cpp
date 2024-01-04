#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct Vertex {
    int key, parent;
    bool isInMST;
};

struct CompareVertices {
    bool operator()(const Vertex& v1, const Vertex& v2) const {
        return v1.key > v2.key;
    }
};

void primMST(vector<vector<Edge>>& graph, int root) {
    int V = graph.size();
    vector<Vertex> vertices(V);

    priority_queue<Vertex, vector<Vertex>, CompareVertices> minHeap;

    for (int u = 0; u < V; ++u) {
        vertices[u].key = numeric_limits<int>::max();
        vertices[u].parent = -1;
        vertices[u].isInMST = false;
        if (u == root) {
            vertices[u].key = 0;
        }
        minHeap.push(vertices[u]);
    }

    while (!minHeap.empty()) {
        Vertex u = minHeap.top();
        minHeap.pop();

        if (u.isInMST) continue;
        u.isInMST = true;

        for (const Edge& edge : graph[u.parent]) {
            int v = edge.v;
            if (!vertices[v].isInMST && edge.weight < vertices[v].key) {
                vertices[v].key = edge.weight;
                vertices[v].parent = u.parent;
                // Invalidating the element in the priority queue
                minHeap.push(vertices[v]);
            }
        }
    }

    // Print the MST
    for (int i = 0; i < V; ++i) {
        if (i != root) {
            cout << vertices[i].parent << endl;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }

    primMST(graph, 0);

    return 0;
}
