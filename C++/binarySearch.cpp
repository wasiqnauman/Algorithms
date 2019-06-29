#include <iostream>

using namespace std;

int binarySearch(int A[],int N, int key)
{
    int hi = N - 1;
    int low = 0;
    while (low <= hi)
    {
        int mid = low + (hi - low) / 2;
        if (key < A[mid])
            hi = mid - 1;
        else if (key > A[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
