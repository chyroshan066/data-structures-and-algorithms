import math
G = {
    'v1': {'v2': 1, 'v4': 4},
    'v2': {'v1': 1, 'v3': 3, 'v5': 3},
    'v4': {'v1': 4, 'v5': 1},
    'v5': {'v2': 3, 'v3': 1, 'v4': 1, 'v6': 4},
    'v3': {'v2': 3, 'v5': 1, 'v6': 2},
    'v6': {'v3': 2, 'v5': 4}
}

def prims_algorithm(G, start):   #prims algorithm
    T = []  
    included_vertices = {start} 
    edges = []
    total_cost = 0 
    

    for neighbor, weight in G[start].items():
        edges.append((weight, start, neighbor))  #adding starting edges
    edges.sort()
    
    while len(included_vertices) < len(G):  
        while edges:
            weight, u, v = edges.pop(0)  
            if v not in included_vertices:
                T.append(f'{u} - {v} ({weight})') 
                included_vertices.add(v)
                total_cost += weight  
                for neighbor, w in G[v].items():
                    if neighbor not in included_vertices:
                        edges.append((w, v, neighbor))   #adding new edges
                edges.sort()
                break  
    
    return T, total_cost  


start = 'v1'
mst_edges, total_cost = prims_algorithm(G, start)
print("Minimum Spanning Tree Edges:")
for edge in mst_edges:
    print(edge)
print(f'Total cost of MST: {total_cost}')