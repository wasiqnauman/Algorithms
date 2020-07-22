#include <iostream>

using namespace std;

struct Node
{
    string item;
    Node* next;
    Node(string item, Node* next) : item(item), next(next) {}
};
class Queue
{
private:
    Node* first;
    Node* last;
public:
    Queue() : first(nullptr), last(nullptr) {}
    void enqueue(string item);
    bool isEmpty();
    string dequeue();
    void print();   // shows everything in the queue
};

void Queue::enqueue(string item)
{
    Node* t = last;
    last = new Node(item, nullptr);
    if (first == nullptr)
    {
        first = last;
    }
    else
        t->next = last;
}
bool Queue::isEmpty()
{
    return first == nullptr;
}
string Queue::dequeue()
{
    if (first == nullptr)
    {
        cout << "Queue is empty!" << endl;
        exit(1);
    }
    string item = first->item;
    Node* t = first->next;
    delete first;
    first = t;
    return item;
}
void Queue::print()
{
    Node* c = first;
    while (c != nullptr)
    {
        cout << c->item << endl;
        c = c->next;
    }
}
int main()
{
    Queue X;
    string s;
    while (cin >> s)
    {
        if (s == "-")
            cout << X.dequeue();
        else
            X.enqueue(s);
    }
}