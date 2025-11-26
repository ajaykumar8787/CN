#include <iostream>
using namespace std;

#define INF 9999
#define MAX 10

// Bellman-Ford algorithm for single source shortest paths
void bellmanFord(int cost[MAX][MAX], int nodes, int src) {
    int dist[MAX];

    // Step 1: Initialize distances
    for (int i = 0; i < nodes; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Step 2: Relax all edges (nodes-1 times)
    for (int k = 0; k < nodes - 1; k++) {
        for (int u = 0; u < nodes; u++) {
            for (int v = 0; v < nodes; v++) {
                if (cost[u][v] != INF && dist[u] != INF) {
                    if (dist[u] + cost[u][v] < dist[v]) {
                        dist[v] = dist[u] + cost[u][v];
                    }
                }
            }
        }
    }

    // Step 3: Print routing table for this router
    cout << "\nRouter " << src << " routing table:\n";
    for (int i = 0; i < nodes; i++) {
        if (dist[i] == INF)
            cout << "To Router " << i << " → Cost: INF (no path)\n";
        else
            cout << "To Router " << i << " → Cost: " << dist[i] << "\n";
    }
}

int main() {
    int nodes;
    cout << "Enter number of routers: ";
    cin >> nodes;

    int cost[MAX][MAX];
    cout << "Enter cost adjacency matrix (use 9999 for no link):\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> cost[i][j];
        }
    }

    cout << "\n=== Distance Vector Routing using Bellman-Ford ===\n";
    for (int src = 0; src < nodes; src++) {
        bellmanFord(cost, nodes, src);
    }

    return 0;
}

