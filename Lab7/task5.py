import math
G = {
    'v1': {'v2': 1, 'v4': 4},
    'v2': {'v1': 1, 'v3': 3, 'v5': 3},
    'v4': {'v1': 4, 'v5': 1},
    'v5': {'v2': 3, 'v3': 1, 'v4': 1, 'v6': 4},
    'v3': {'v2': 3, 'v5': 1, 'v6': 2},
    'v6': {'v3': 2, 'v5': 4}
}

def find(parent, vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find(parent, parent[vertex])  
    return parent[vertex]

def union(parent, rank, root1, root2):
    if rank[root1] < rank[root2]:
        parent[root1] = root2
    elif rank[root1] > rank[root2]:
        parent[root2] = root1
    else:
        parent[root2] = root1
        rank[root1] += 1

def kruskals_algorithm(G):
    edges = []
    for vertex in G:
        for neighbor, weight in G[vertex].items():
            if (neighbor, vertex, weight) not in edges:
                edges.append((vertex, neighbor, weight))
    edges.sort(key=lambda edge: edge[2])
    
    parent = {vertex: vertex for vertex in G}  
    rank = {vertex: 0 for vertex in G}
    mst_edges = []
    total_cost = 0
    
    for u, v, weight in edges:  
        root1 = find(parent, u)
        root2 = find(parent, v)
        if root1 != root2:  
            union(parent, rank, root1, root2)
            mst_edges.append((u, v, weight))

            total_cost += weight
    
    return mst_edges, total_cost



mst_edges, total_cost = kruskals_algorithm(G)
print("Minimum Spanning Tree Edges:")
for edge in mst_edges:
    print(edge)
print(f'Total cost of MST: {total_cost}')