def Mul(A, n, vector):
    res = [0] * n  

    for i in range(n):
        for j in range(n):
            res[i] += A[i][j] * vector[j]
    
    return res

def Krilov(A, n, vector):
    mat = [[0] * n for _ in range(n)]
    g = 0
    
    mat[g] = Mul(A, n, vector)
    while g < n - 1:
        vector = mat[g]
        g = g + 1
        mat[g] = Mul(A, n, vector)
    
    return mat

def printV(mat, n, vector):
    print(f"{mat[n - 1]}")
    for i in range(n - 2, -1, -1):
        print(f"b{i + 1} = {mat[i]}")
    print(f"b0 = {vector}")

"""
B = [[5,-2,0],
     [-2,3,-1],
     [0,-1,1]]

C = [[1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]]

A = [[1, 2, 3, 4, 5],
    [6, 7, 8, 9, 10],
    [11, 12, 13, 14, 15],
    [16, 17, 18, 19, 20],
    [21, 22, 23, 24, 25]]
"""
A = [[1,-1,4],
     [3,2,-1],
     [2,1,-1]]
vector = [1,0,0]

n = A.__len__()
mat = Krilov(A, n, vector)
printV(mat, n, vector)








