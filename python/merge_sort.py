import math
A = [3,41,52,26,38,57,9,49]

def merge(A,p,q,r):
    n1 = q-p+1
    n2 = r-q
    print("value of n1 and n2",n1,n2)
    L = [999],R = [999]
    for i in range(1,n1):
        L.append(p + i - 1)
    for j in range(1,n2):
        R.append(q + j)
    L.append(999),R.append(999)
    print(L)
    print(R)


def mergesort(A,p,r):
    if p < r:
        q = math.floor((p + r) / 2)
        mergesort(A,p,q)
        mergesort(A,q+1,r)
        merge(A,p,q,r)

mergesort(A,0,7)
print(A)