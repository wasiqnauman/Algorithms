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
    queue<int>pre;
    queue<int>post;
    stack<int>reversePost;

public:
    Graph(int V) {
        this->V = V;
        adj.assign(V,vector<int>());

    }

    void dfs(int v) {
        vector<bool>marked(V,false);

        for(int v=0; v<V;v++) {
            if(!marked[v]) {
                _dfs(v,marked);
            }
        }
    }
    void _dfs(int v, vector<bool> &marked) {
        pre.push(v);
        marked[v] = true;
        cout << v << endl;
        for(int w: adj[v]) {
            if (!marked[w])
                _dfs(w,marked);
        }
        post.push(v);
        reversePost.push(v);
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
    bool hasCycle()
    {
        vector<bool>marked(V,false);
        vector<bool>on_stack(V,false);
        bool found_cycle = false;
        for(int i=0; i<V; i++)
        {
            if(!marked[i])
                dfs_cycle(i, marked, on_stack, found_cycle);
        }
        return found_cycle;
    }
    void dfs_cycle(int v, vector<bool>&marked, vector<bool>&on_stack, bool& found)
    {
        marked[v] = true;
        on_stack[v] = true;

        for(int w: adj[v])
        {
            if(on_stack[w])
                found = true;
            else
                dfs_cycle(w, marked, on_stack, found);
        }
        on_stack[v] = false;
    }
    int num_components() {
        vector<bool>marked(V,false);
        vector<int>id(V,-1);
        int count=0;

        for(int v=0; v< V;v++) {
            if(!marked[v]) {
                _dfs_CC(marked,id,count,v);
                count++;
            }
        }
        return count;
    }
    void _dfs_CC(vector<bool>&marked,vector<int>&id, int count, int v) {
        marked[v] = true;
        id[v] = count;
        cout << "v:" << v << " id:" << count << endl;
        for(int w:adj[v]) {
            if(!marked[w]) {
                _dfs_CC(marked,id,count,w);
            }
        }
    }
    void preOrder()
    {
        while(!pre.empty()){
            cout << pre.front() << " ";
            pre.pop();
        }
    }
    void postOrder()
    {
        while(!post.empty()){
            cout << post.front() << " ";
            post.pop();
        }
    }
    void reverse_postOrder()
    {
        while(!reversePost.empty()){
            cout << reversePost.top() << " ";
            reversePost.pop();
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
//    g.add_directed_edge(6,3);       // add a cycle 6 - 3
//    cout << g.hasCycle() << endl;
//    g.print_topo_sort();
    g.dfs(0);
    cout << endl;
    g.reverse_postOrder();
    cout << endl;
    g.print_topo_sort();




}