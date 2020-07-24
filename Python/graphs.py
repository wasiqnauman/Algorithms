from queue import Queue
from _collections import deque

class Graph:
    def __init__(self,V):
        self.V = V
        self.adj = {}

        for i in range(0,V):
            self.adj[i] = []

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def add_directed_edge(self,u,v):
        self.adj[u].append(v)

    def dfs(self, v):
        marked = [False for i in range(0, self.V)]
        for v in range(0, self.V):
            if not marked[v]:
                self._dfs(v, marked)

    def _dfs(self, v, marked):
        marked[v] = True
        print(v)
        for w in self.adj[v]:
            if not marked[w]:
                self._dfs(w, marked)

    def num_components(self):
        id = {}
        count = 0
        marked = [False for i in range(0, self.V)]

        for v in range(0, self.V):
            if not marked[v]:
                self.dfs_CC(v, id, count, marked)
                count += 1

        return count

    def dfs_CC(self, v, id, count, marked):
        marked[v] = True
        id[v] = count
        print(f'v:{v}, id:{id[v]}')
        for w in self.adj[v]:
            if not marked[w]:
                self.dfs_CC(w, id, count, marked)

    def is_connected(self):
        marked = [False for i in range(0,self.V)]
        self._dfs(0,marked)
        return all(marked)

    def BFS(self,s):
        marked = [False for i in range(0, self.V)]
        q = Queue()
        q.put(s)
        marked[s] = True
        while not q.empty():
            v = q.get()
            print(v)
            for w in self.adj[v]:
                if not marked[w]:
                    q.put(w)
                    marked[w] = True

    def topo_sort(self):
        """
        returns the topological order of the graph
        also called the reversePostOrder
        using deque over list as it provides O(1) operations
        as compared to O(n) for the list

        time: O(|V| + |E|)
        """
        marked = [False for i in range(0, self.V)]
        reversePost = deque()

        for v in range(0,self.V):
            if not marked[v]:
                self._dfs_topo(marked,reversePost,v)

        return reversePost

    def _dfs_topo(self,marked,reversePost,v):
        marked[v] = True
        for w in self.adj[v]:
            if not marked[w]:
                self._dfs_topo(marked,reversePost,w)

        reversePost.append(v)


    def print_topo_order(self):
        reversePost = self.topo_sort()
        print('Topological Order:')
        while reversePost:
            print(reversePost.pop(), end=" ")



if __name__ == "__main__":
    g = Graph(7)
    # g.addEdge(0, 1)
    # g.addEdge(0, 2)
    # g.addEdge(0, 6)
    # g.addEdge(0, 5)
    # g.addEdge(5, 3)
    # g.addEdge(5, 4)
    # g.addEdge(6, 4)
    # g.BFS(0)
    g.add_directed_edge(0, 1)
    g.add_directed_edge(0, 5)
    g.add_directed_edge(0, 2)
    g.add_directed_edge(3, 2)
    g.add_directed_edge(3, 5)
    g.add_directed_edge(5, 2)
    g.add_directed_edge(1, 4)
    g.add_directed_edge(3, 4)
    g.add_directed_edge(3, 6)
    g.add_directed_edge(6, 4)
    g.add_directed_edge(6, 0)
    g.print_topo_order()
