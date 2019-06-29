def binarySearch(A,key):
    hi = len(A)-1
    low = 0
    while low<= hi:
        mid = low + (hi-low)//2
        if key <A[mid]:
            hi = mid - 1
        elif key>A[mid]:
            low = mid+1
        else:
            return mid
    return -1

A = [0,1,2,3,4,5,6,7,8,9,10]

print(binarySearch(A,3))
