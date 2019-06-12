#include <iostream>

using namespace std;

static const int N = 1000;

class quickFindUF
{
private:
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
    int id[N];

    int root(int i)
    {
        while (i != id[i])
        {
            i = id[i];
        }
        return i;
    }
public:
    quickUnionUF()
    {
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }
    void Union(int p, int q)
    {
        int i = root(p);
        id[i] = root(q);
    }

};
class quickUnionWPCUF   //weighted with path compression
{
private:
    int id[N];
    int sz[N];
    int root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];   //path-compression
            i = id[i];
        }
        return i;
    }
public:
    quickUnionWPCUF()
    {
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }
    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j)   //roots are the same, so they must be connected already
            return;
        if (sz[i] > sz[j])   //weighing
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        else
        {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
};
int main()
{
    //test
    quickUnionUF UF;
    UF.Union(4, 3);
    UF.Union(3, 8);
    UF.Union(6, 5);
    UF.Union(9, 4);
    UF.Union(2, 1);
    cout << UF.connected(8, 9);
}