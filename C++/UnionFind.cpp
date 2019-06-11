#include <iostream>

using namespace std;

class quickFindUF
{
private:
    static const int N = 1000; //length of array
    int id[N];   //create new array of length N
public:
    quickFindUF()   //initialize array to values 0<=i<N
    {
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    bool connected(int p, int q)   //if id[p] == id[q] they are connected
    {
        return id[p] == id[q];
    }
    void Union(int p, int q)   //change id[p] to id[q]
    {
        int pID = id[p];
        int qID = id[q];
        for (int i = 0; i < N; i++)
            if (id[i] == pID)
                id[i] = qID;
    }
};

class quickUnionUF
{
private:
    static const int N = 1000;
    int id[N];
    
    int root(int i)   //returns the root of a parent
    {
        while (i != id[i])
            i = id[i];
        return i;
    }
public:
    quickUnionUF()
    {
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    bool connected(int p, int q)   //two objects are connected if their root is the same
    {
        return root(p) == root(q);
    }
    void Union(int p, int q)   //change the root of p to root of q
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

};

int main()
{
    //random testing of functions
    quickUnionUF UF;
    UF.Union(4, 3);
    UF.Union(3, 8);
    UF.Union(6, 5);
    UF.Union(9, 4);
    UF.Union(2, 1);
    cout << UF.connected(8, 9);
}