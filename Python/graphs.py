from queue import Queue

class Graph:
    def __init__(self,V):
        self.V = V
        self.adj = {}

        for i in range(0,V):
            self.adj[i] = []

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

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




g = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(0, 6)
g.addEdge(0, 5)
g.addEdge(5, 3)
g.addEdge(5, 4)
g.addEdge(6, 4)
g.BFS(0)
