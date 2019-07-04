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
        s = new string[capacity];
    }
    
    void resize(int newCapacity)
    {
        string* copy = new string[newCapacity];
        for (int i = 0; i < N; i++)
        {
            copy[i] = s[i];
        }
        delete[] s;
        s = copy;
        capacity = newCapacity;
    }
    string pop()
    {
        string item = s[--N];
        if (N > 0 && N == capacity / 4)
            resize(capacity / 2);
        return item;
    }
    void push(string val)
    {
        if (N == capacity)
            resize(capacity * 2);
        s[N++] = val;
    }
    bool isEmpty()
    {
        return N == 0;
    }
};

int main()
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