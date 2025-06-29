from collections import deque

# BFS function to find an augmenting path
def bfs(rGraph, s, t, parent):
    visited = [False] * len(rGraph)
    queue = deque([s])
    visited[s] = True

    while queue:
        u = queue.popleft()
        for v, capacity in enumerate(rGraph[u]):
            if not visited[v] and capacity > 0:
                queue.append(v)
                visited[v] = True
                parent[v] = u
                if v == t:
                    return True
    return False

# Ford-Fulkerson implementation
def ford_fulkerson(graph, source, sink):
    rGraph = [row[:] for row in graph]  # Residual graph copy
    parent = [-1] * len(graph)
    max_flow = 0

    while bfs(rGraph, source, sink, parent):
        path_flow = float('inf')
        v = sink
        while v != source:
            u = parent[v]
            path_flow = min(path_flow, rGraph[u][v])
            v = u

        v = sink
        while v != source:
            u = parent[v]
            rGraph[u][v] -= path_flow
            rGraph[v][u] += path_flow
            v = u

        max_flow += path_flow

    return max_flow

# ---- User Input ----
def main():
   
    n = int(input("Enter number of nodes: "))
    graph = [[0] * n for _ in range(n)]

    e = int(input("Enter number of edges: "))
    print("Enter edges in the format: from to capacity")
    for _ in range(e):
        u, v, c = map(int, input("Edge: ").split())
        graph[u][v] = c

    source = int(input("Enter source node: "))
    sink = int(input("Enter sink node: "))

    max_flow = ford_fulkerson(graph, source, sink)
    print("The maximum possible flow is:", max_flow)

if __name__ == "__main__":
    main()
