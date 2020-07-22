#include <iostream>

using namespace std;


template <class Key>
class maxPQ
{
private:
  Key* pq;
  int N;
  
  void exch(Key& a, Key& b)
  {
    Key temp = a;
    a = b;
    b = temp;
  }

public:
  maxPQ(int size)
  {
    pq = new Key[size];
  }
  bool isEmpty()
  {
    return N == 0;
  }
  void insert(Key x)
  {
    pq[N++] = x;
  }
  Key delMax()
  {
    int max = 0;
    for (int i = 0; i < N; i++)
    {
      if (pq[max] < pq[i])
      {
        max = i;
      }
    }
    exch(pq[max], pq[N - 1]);
    return pq[--N];
  }
};

int main()
{  //test
  maxPQ<string> pq(10);
  pq.insert("P");
  pq.insert("L");
  pq.insert("E");
  cout << pq.delMax();
}

