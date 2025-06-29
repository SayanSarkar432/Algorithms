from collections import defaultdict

def dfs(u, t, visited, parent, residual):
    visited.add(u)
    if u == t:
        return True
    for v in residual[u]:
        if v not in visited and residual[u][v] > 0:
            parent[v] = u
            if dfs(v, t, visited, parent, residual):
                return True
    return False

def ford_fulkerson(capacity, s, t):
    residual = defaultdict(lambda: defaultdict(int))
    for u in capacity:
        for v in capacity[u]:
            residual[u][v] = capacity[u][v]
            residual[v][u] = 0

    max_flow = 0

    while True:
        visited = set()
        parent = {}
        if not dfs(s, t, visited, parent, residual):
            break

        path_flow = float('inf')
        v = t
        while v != s:
            u = parent[v]
            path_flow = min(path_flow, residual[u][v])
            v = u

        v = t
        while v != s:
            u = parent[v]
            residual[u][v] -= path_flow
            residual[v][u] += path_flow
            v = u

        max_flow += path_flow

    return max_flow

if __name__ == "__main__":
    graph = defaultdict(dict)
    num_edges = int(input("Enter number of edges: "))
    print("Enter each edge in the format: from to capacity")
    for _ in range(num_edges):
        u, v, cap = input().split()
        cap = int(cap)
        if v in graph[u]:
            graph[u][v] += cap
        else:
            graph[u][v] = cap
        if u not in graph[v]:
            graph[v] = graph.get(v, {})

    source = input("Enter source node: ")
    sink = input("Enter sink node: ")

    print("Maximum Flow:", ford_fulkerson(graph, source, sink))
