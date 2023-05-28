import time

def errorRelativo(xP, xA):
    return 1 - (xP / xA)

def printSol(variables, n):
    for z in range(n):
        print("x", z, " = ", variables[z])

def Jacobi(ecuaciones, n, tol, iteraciones):
    variables = [0] * n
    valores = [0] * n
    res = 0

    while iteraciones > 0:
        for i in range(n): #Ecuacion
            res = ecuaciones[i][n]
            for j in range(n): #Coeficiente
                if i != j:
                    res += - ecuaciones[i][j] * valores[j]
            res /= ecuaciones[i][i]
            variables[i] = round(res, 4)

        
        for w in range(n):
            """
            if errorRelativo(valores[w], variables[w]) < tol:
                printSol(variables, n)
                return
            """
            valores[w] = variables[w]

        iteraciones = iteraciones - 1

    printSol(variables, n)
                
ecuaciones = [[4, 1, 1, 6],
              [2, -5, 1, -2],
              [1, 2, 7, 10]]

i = time.time()
Jacobi(ecuaciones, ecuaciones.__len__(), 0.00000001, 20)
end = time.time()
print(f"Tiempo de ejecucion : {end - i}")
