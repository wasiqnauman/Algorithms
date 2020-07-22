#include <iostream>

using namespace std;

template<class T>
class maxPQ
{
  T* pq;
  int N = 0;
public:
  maxPQ(int capacity)
  {
    pq = new T[capacity + 1];
  }

  void insert(T x);
  bool isEmpty();
  T delMax();
  void swim(int k);
  void sink(int k);
  void exch(int p, int q);
};

template <class T>
void maxPQ<T>::insert(T x)
{
  pq[++N] = x;
  swim(N);
}
template <class T>
bool maxPQ<T>::isEmpty()
{
  return N == 0;
}
template<class T>
T maxPQ<T>::delMax()
{
  T max = pq[1];
  exch(1, N--);
  sink(1);
 // pq[N+1] = nullptr //to prevent loitering
  return max;
}
template<class T>
void maxPQ<T>::swim(int k)
{
  while (k > 1 && pq[k / 2] < pq[k])
  {
    exch(k / 2, k);
    k = k / 2;
  }
}
template<class T>
void maxPQ<T>::sink(int k)
{
  while (2*k <= N)
  {
    int j = 2*k;
    if (j < N && pq[j] < pq[j + 1])
    {
      j++;
    }
    if (!(pq[k] < pq[j]))
    {
      break;
    }
    exch(k, j);
    k = j;
  }
}
template<class T>
void maxPQ<T>::exch(int p, int q)
{
  T temp = pq[p];
  pq[p] = pq[q];
  pq[q] = temp;
}


int main()
{
  maxPQ<string> heap(10);
  heap.insert("A");
  heap.insert("B");
  heap.insert("C");
  cout << heap.delMax();;
  return 0;
}