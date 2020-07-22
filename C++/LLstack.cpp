#include <iostream>

using namespace std;

struct Node
{
    string val;
    Node* next;

    Node(string val, Node* next)
    {
        this->val = val;
        this->next = next;
    }
};

class Stack
{
private:
    Node* first;
public:
    Stack()
    {
        this->first = nullptr;
    }
    void push(string val);
    string pop();
    bool isEmpty();
};

void Stack::push(string val)
{
    first = new Node(val, this->first);   //create a new node at the start of the linked list
}

string Stack::pop()
{
    if (first != nullptr)
    {
        Node* last = first;   // the last node on the linked list
        string item = last->val;   // the item to be returned
        first = first->next;
        delete last;   // delete the last node to free memory
        return item;
    }
    cout << "Stack is Empty" << endl;  // to avoid underflow of popping an empty stack
}

bool Stack::isEmpty()
{
    return first == nullptr;
}

int main()   //test
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