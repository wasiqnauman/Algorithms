#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    void add_directed_edge(int v,int w) {
        adj[v].push_back(w);
    }
    stack<int> topo_sort() {
        vector<bool>marked(V, false);
        stack<int>reversePost;

        for(int i=0;i<V;i++) {
            if(!marked[i])
                _dfs_topo(marked,reversePost, i);
        }
        return reversePost;
    }
    void _dfs_topo(vector<bool>&marked,stack<int>&reversePost,int v) {
        marked[v] = true;

        for(int w:adj[v]) {
            if(!marked[w])
            {
                _dfs_topo(marked,reversePost,w);
            }
        }
        reversePost.push(v);
    }
    void print_topo_sort() {
        stack<int>s = this->topo_sort();
        cout << "Topological Order: " << endl;
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};


int main() {
    Graph g(7);
//    g.add_edge(0,1);
//    g.add_edge(0,2);
//    g.add_edge(0,6);
//    g.add_edge(0,5);
//    g.add_edge(5,4);
//    g.add_edge(5,3);
//    g.add_edge(6,4);
    g.add_directed_edge(0,1);
    g.add_directed_edge(0,5);
    g.add_directed_edge(0,2);
    g.add_directed_edge(3,2);
    g.add_directed_edge(3,5);
    g.add_directed_edge(5,2);
    g.add_directed_edge(1,4);
    g.add_directed_edge(3,4);
    g.add_directed_edge(3,6);
    g.add_directed_edge(6,4);
    g.add_directed_edge(6,0);
    g.print_topo_sort();



}