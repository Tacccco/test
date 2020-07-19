import random

r=[[random.randint(0,9) for i in range(0,5)] for j in range(0,5)]
print(r)
j=1
for i in range(5):
    j=i
    r[i][j],r[i][4-j]=r[i][4-j],r[i][j]
    i=i+1
print(r)
