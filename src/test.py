import numpy as np

for i in range(len(adj_matrix)):
    for j in range(i + 1, len(adj_matrix)):
        print(adj_matrix[i][j])
    print(" ")
