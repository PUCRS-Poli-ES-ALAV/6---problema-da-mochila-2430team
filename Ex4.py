def Knapsack(lista_de_items:list, capacidade:int):
    ops = 0
    mat = []
    mat.extend([[0 for j in range(capacidade+1)] for i in range(len(lista_de_items)+1)])
    for i, item in enumerate(lista_de_items):
        i = i+1
        for j in range(capacidade+1):
            ops += 1
            if i == 0: mat[0][j]
            elif j == 0: mat[i][0] = 0
            else:
                if item[0] <= j:
                    mat[i][j] = max(mat[i-1][j], item[1]+mat[i-1][j-item[0]])
                else:
                    mat[i][j] = mat[i-1][j]
    for l in mat:
        print(l)
    print(ops)
    return mat[-1][-1]
print(Knapsack([(5,2),(2,4),(2,2),(1,3)], 7))