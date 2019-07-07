#include <iostream>

using namespace std;

class Queue
{
private:
    string* s;
    int N;   //pointer to the end of the queue
    int capacity;
    int start;   //pointer to the start of the queue;
public:
    Queue()
    {
        s = new string[1];
        N = 0;
        capacity = 1;
        start = 0;
    }
    void resize(int newSize);
    bool isEmpty();
    void enqueue(string item);
    string dequeue();
};

void Queue::resize(int newSize)
{
  string* copy = new string[newSize];
  for(int i = 0; i<N;i++)
  {
    copy[i] = s[i];
  }
  string* old = s;
  s = copy;
  capacity = newSize;
  delete[] old;
}
bool Queue::isEmpty()
{
  return N == 0;
}
void Queue::enqueue(string item)
{
  if(N == capacity)
  {
    resize(capacity*2);
  }
  s[N++] = item;
}
string Queue::dequeue()
{
  if (start == N)
  {
    cout << "Queue is empty" << endl;
    exit(1);
  }
  string item = s[start++];
  if(N>0 && N==capacity/4)
  {
    resize(capacity/2);
  }
  return item;
}
int main()
{
  Queue X;
  string s;
  while(cin>>s)
  {
    if(s=="-")
    {
      cout << X.dequeue() << " ";
    }
    else
      X.enqueue(s);
  }
  return 0;
}
