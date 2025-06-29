#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 100  // Maximum number of vertices

// BFS to find if there is a path from source to sink in residual graph.
// Also stores the path in parent[]
bool bfs(int rGraph[V][V], int s, int t, int parent[], int vertices) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    int queue[V], front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

// Ford-Fulkerson algorithm
int fordFulkerson(int graph[V][V], int s, int t, int vertices) {
    int u, v;
    int rGraph[V][V];

    // Create residual graph and initialize it
    for (u = 0; u < vertices; u++)
        for (v = 0; v < vertices; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];  // Array to store path
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, vertices)) {
        int path_flow = INT_MAX;

        // Find minimum residual capacity of the edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

        // Update residual capacities
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int vertices, edges;
    int graph[V][V];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize graph with 0s
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges :\n");
    for (int i = 0; i < edges; i++) {
        int u, v, cap;
        scanf("%d %d %d", &u, &v, &cap);
        graph[u][v] = cap;
    }

    int source, sink;
    printf("Enter source node: ");
    scanf("%d", &source);
    printf("Enter sink node: ");
    scanf("%d", &sink);

    int maxFlow = fordFulkerson(graph, source, sink, vertices);
    printf("The maximum possible flow is: %d\n", maxFlow);

    return 0;
}
