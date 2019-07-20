#include <iostream>

using namespace std;

template<class T> 
void merge(T a[], T* aux, int lo, int mid, int hi)
{
  for (int i = lo; i <= hi; i++)   //copy into auxillary array
  {
    aux[i] = a[i];
  }
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++)   //merge
  {
    if (i > mid)
      a[k] = aux[j++];
    else if (j > hi)
      a[k] = aux[i++];
    else if (aux[j] < a[i])
      a[k] = aux[j++];
    else
      a[k] = aux[i++];
  }
}
template<class T>
void sort(T a[], T* aux, int lo, int hi)
{
  if (hi >= lo)   //does not require sorting
    return;
  int mid = lo + (hi - lo) / 2;
  sort(a, aux, lo, mid);
  sort(a, aux, mid + 1, hi);
  merge(a, aux, lo, mid, hi);
}
template<class T>
void sort(T a[],int N)
{
  T* aux = new T[N];  //pointer to auxillary array
  sort(a, aux, 0, N-1);
  delete[] aux;
}

int main()
{   //test
  const int N = 100000;
  int A[N];
  for (int i = N-1; i >=0; i--)
  {
    A[i] = i;
  }
  sort(A, N);
  for (int i = 0; i < 100; i++) {
    cout << A[i] << endl;
  }
}