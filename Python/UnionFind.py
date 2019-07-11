#Note: I am a C++ developer trying to teach myself Python, so my main focus is getting the code to work.

class UF:
    def __init__(self,N):
        self.id = []
        self.sz = []
        for i in range(N):
            self.id.append(i)
            self.sz.append(1)
    
    def connected(self, p, q):
        return self.root(p) == self.root(q)
    
    def root(self,i):
        while i != self.id[i]:
            self.id[i] = self.id[self.id[i]]
            i = self.id[i]
        return i
    
    def connect(self, p, q):
        i = self.root(p)
        j = self.root(q)
        if i == j:
            return
        if self.sz[i] > self.sz[j]:
            self.id[j] = self.id[i]
            self.sz[i] += self.sz[j]
        else:
            self.id[i] = self.id[j]
            self.sz[j] += self.id[i]

x = UF(10)
x.connect(1,3)
x.connect(3,4)
print(x.connected(1,4))
    