#include <iostream>

using namespace std;

class Stack
{
private:
    int N;
    int capacity;
    string* s;
public:
    Stack()
    {
        N = 0;
        capacity = 1;
        s = new string[capacity];   //create initial array with capacity 1
    }

    void resize(int newCapacity);
    string pop();
    void push(string val);
    bool isEmpty();
};
void Stack::resize(int newCapacity)
{
    string* copy = new string[newCapacity];   //create a new array with twice the capacity of the previous one
    for (int i = 0; i < N; i++)   //copy the data from old to new array
    {
        copy[i] = s[i];
    }
    delete[] s;   //delete the old array to clear memory
    s = copy;
    capacity = newCapacity;
}
string Stack::pop()
{
    string item = s[--N];
    if (N > 0 && N == capacity / 4)   //shrink the array
        resize(capacity / 2);
    return item;
}
void Stack::push(string val)
{
    if (N == capacity)
        resize(capacity * 2);
    s[N++] = val;
}
bool Stack::isEmpty()
{
    return N == 0;
}

int main()  //test
{
    Stack X;
    string s;
    while (cin >> s)
    {
        if (s == "-")
        {
            cout << X.pop() << " ";
        }
        else
            X.push(s);
    }
}
