

# Define infinity as a large number
INF = float('inf')

# Get number of vertices from user
V = int(input("Enter number of vertices: "))

# Initialize distance matrix
dist = []

print("Enter the adjacency matrix (use 'INF' for no edge):")
for i in range(V):
    row = input().split()
    dist_row = []
    for val in row:
        if val == 'INF':
            dist_row.append(INF)
        else:
            dist_row.append(int(val))
    dist.append(dist_row)

# Floyd-Warshall algorithm
for k in range(V):
    for i in range(V):
        for j in range(V):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

# Print the final shortest distance matrix
print("\nShortest distances between every pair of vertices:")
for i in range(V):
    for j in range(V):
        if dist[i][j] == INF:
            print("INF", end=" ")
        else:
            print(dist[i][j], end=" ")
    print()