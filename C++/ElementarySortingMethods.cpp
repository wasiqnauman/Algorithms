#include <iostream>

using namespace std;

template <class T>
void exch(T &i, T &j)
{
  T swap = i;
  i = j;
  j = swap;
}

template <class T>
void selSort(T A[], int N)
{
  int i, j, min;
  for (i = 0; i < N; i++)
  {
    min = i;
    for (j = i + 1; j < N; j++)
    {
      if (A[j]<A[min])
      {
        min = j;
      }
    }
    exch(A[i],A[min]);
  }
}

template <class T>
void insertionSort(T A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (A[j] < A[j - 1])
        exch(A[j], A[j - 1]);
      else
        break;
    }
  }
}
template<class T>
void shellSort(T A[], int N)
{
  int h = 1;
  while (h > N / 3)
  {
    h = 3 * h + 1;   // 3x+1 increment sequence
  }
  while (h >= 1)
  {
    for (int i = h; i < N; i++)
    {
      for (int j = i; j >= h && A[j] < A[j - 1]; j -= h)   // insertion sort
      {
        T temp = A[j];  // swap
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
    h = h / 3;
  }
}
int main()   //test
{
  int A[10];
  for (int i(10), j(0); i > 0, j < 10; i--, j++)
  {
    A[j] = i;
    cout << A[j] << " ";
  }
  cout << endl;
  shellSort(A, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << A[i] << " ";
  }
}