

import math

def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0 if i == j else math.inf for j in range(n+1)]
         for i in range(n+1)]
    s = [[0 for _ in range(n+1)]
         for _ in range(n+1)]
    for l in range(2, n+1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            m[i][j] = math.inf
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return m, s

def print_optimal_parens(s, i, j):
    if i == j:
        print(f"A{i}", end="")
    else:
        print("(", end="")
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j] + 1, j)
        print(")", end="")

if __name__ == "__main__":
    dims = list(map(int, input("Enter dimensions (space-separated): ").split()))
    m, s = matrix_chain_order(dims)
    n = len(dims) - 1
    print(f"Minimum multiplications: {m[1][n]}")
    print("Optimal parenthesization: ", end="")
    print_optimal_parens(s, 1, n)
    print()
