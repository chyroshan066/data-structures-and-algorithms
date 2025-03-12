def warshall(w):
    n=len(w)
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                w[i][j]=w[i][j] or (w[i][k] and w[k][j])
    return w

w=[
    [0,1,0,0,0],
    [0,0,1,0,0],
    [0,0,0,1,0],
    [0,0,0,0,1],
    [0,0,1,0,0]
]

print("Adjancency matrix:")
for row in w:
    print(row)

transitive_closure=warshall(w)
print("Transitive closure:")
for row in transitive_closure:
    print(row)