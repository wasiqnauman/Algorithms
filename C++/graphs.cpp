#include <iostream>
#include <vector>

using namespace std;

struct vertex {
    vector<int>adj;
};
class Graph {
protected:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.assign(V,vector<int>());
    }

    void dfs(int v) {
        vector<bool>marked(V,false);

        for(int w: adj[v]) {
            if(!marked[w]) {
                _dfs(v,marked);
            }
        }
    }
    void _dfs(int v, vector<bool> &marked) {
        marked[v] = true;
        cout << v << endl;
        for(int w: adj[v]) {
            if (!marked[w])
                _dfs(w,marked);
        }
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int main() {
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,6);
    g.add_edge(0,5);
    g.add_edge(5,4);
    g.add_edge(5,3);
    g.add_edge(6,4);
    g.dfs(0);

}