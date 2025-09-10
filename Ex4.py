from datetime import datetime

def Knapsack(lista_de_items:list, capacidade:int):
    t = datetime.now()
    ops = 0
    itr = 0
    mat = []
    mat.extend([[0 for j in range(capacidade+1)] for i in range(len(lista_de_items)+1)])
    ops += len(mat)
    for i, item in enumerate(lista_de_items):
        i = i+1
        ops += 1
        for j in range(capacidade+1):
            itr += 1
            ops += 1
            if i == 0: ops +=1; mat[0][j]
            elif j == 0: ops += 2; mat[i][0] = 0
            else:
                ops += 2
                if item[0] <= j:
                    ops += 1
                    mat[i][j] = max(mat[i-1][j], item[1]+mat[i-1][j-item[0]])
                    ops += 6
                else:
                    ops += 1
                    mat[i][j] = mat[i-1][j]
                    ops += 2
    for l in mat:
        print(l)
    print("Itr:",itr)
    print("Ops:",ops)
    print("Time:",(datetime.now()-t).microseconds,"micro_s ")
    return mat[-1][-1]
print(Knapsack([(5,2),(2,4),(2,2),(1,3)], 7))