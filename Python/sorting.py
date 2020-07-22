def insertionSort(A):
    for i in range(len(A)):
        key = i
        while key > 0 and A[key] < A[key-1]:
            (A[key], A[key-1]) = (A[key-1], A[key])
            key -= 1

def selectionSort(A):
    for i in range(len(A)):
        minimum = i
        for j in range(i+1, len(A)):
            if A[j] < A[minimum]:
                minimum = j
        (A[i],A[minimum]) = (A[minimum],A[i])

def shellSort(A):
    h = 1
    N = len(A)
    while(h>N/3):
        h = 3*h + 1
    while(h>=1):
        for i in range(h,N):
            j = i
            while j>=h and A[j]<A[j-1]:
                (A[j], A[j-1]) = (A[j-1], A[j])
                j -= h
        h = h/3


x = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
shellSort(x)
print(x)