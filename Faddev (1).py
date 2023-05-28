def multMat(A, B, n):
    mat = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            for k in range(n):
                mat[i][j] += A[i][k] * B[k][j]

    return mat

def printC(c, n):
    z = n - 1
    print("Polinomio Caracteristico : ")
    print(f"x^3 + ", end = "")
    for i in range(n):
        if i == n - 1:
            print(f"{c[i]}", end = "")
            return
        print(f"{c[i]}x^{z} + ", end = "")
        z -= 1
    

def Faddev(A, n):
    c = [0] * n
    B = [[0] * n for _ in range(n)]
    Baux = [[0] * n for _ in range(n)]
    b = 0
    bAux = 0

    for i in range(n):
        B[i][i] = 1
        b += A[i][i]
    b *= -1

    for i in range(n):
        c[i] = int(b)
        Baux = multMat(A, B, n) 
        for j in range(n):
            Baux[j][j] += b
            
        B = Baux
        Baux = multMat(A, B, n)
        
        bAux = 0
        for k in range(n):
            bAux += Baux[k][k]
        
        bAux *= -1 / (i + 2)
        b = bAux
    
    printC(c, n)
    return c         

A = [[1, -1, 4],
     [3, 2, -1],
     [2, 1, -1]]


n = A.__len__()
c = Faddev(A, n)


