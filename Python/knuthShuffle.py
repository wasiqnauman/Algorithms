from random import randint


def shuffle(A):
    N = len(A)
    for i in range(N):
        r = randint(0, i)
        (A[i], A[r]) = (A[r], A[i])


#test

x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
shuffle(x)
print(x)