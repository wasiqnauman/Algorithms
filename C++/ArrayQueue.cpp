#include <iostream>

using namespace std;

template<class T>
class Queue
{
private:
    T* s;
    int N;   //pointer to the end of the queue
    int capacity;
    int start;   //pointer to the start of the queue;
public:
    Queue()
    {
        s = new T[1];
        N = 0;
        capacity = 1;
        start = 0;
    }
    void resize(int newSize);
    bool isEmpty();
    void enqueue(T item);
    T dequeue();
};

template <class T> void Queue<T>::resize(int newSize)
{
    T* copy = new T[newSize];
    for (int i = 0; i < N; i++)
    {
        copy[i] = s[i];
    }
    T* old = s;
    s = copy;
    capacity = newSize;
    delete[] old;
}
template <class T> bool Queue<T>::isEmpty()
{
    return N == 0;
}
template <class T> void Queue<T>::enqueue(T item)
{
    if (N == capacity)
    {
        resize(capacity * 2);
    }
    s[N++] = item;
}
template <class T> T Queue<T>::dequeue()
{
    if (start == N)
    {
        cout << "Queue is empty" << endl;
        exit(1);
    }
    T item = s[start++];
    if (N > 0 && N == capacity / 4)
    {
        resize(capacity / 2);
    }
    return item;
}
int main()
{
    Queue<string> X;
    string s;
    while (cin >> s)
    {
        if (s == "-")
        {
            cout << X.dequeue() << " ";
        }
        else
            X.enqueue(s);
    }
    return 0;
}
