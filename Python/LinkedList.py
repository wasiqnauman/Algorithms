#Note: I am a C++ developer trying to learn Python, so my main focus is getting the code to work.
class Node:
    def __init__(self,item):
        self.item = item
        self.next = None
    def setNext(self,next):
        self.next = next
    def getNext(self):
        return self.next
    def getItem(self):
        return self.item

class List:
    def __init__(self):
        self.first = None
        self.last = None

    def add(self,item):
        if self.first == None:
            self.last = Node(item)
            self.last.setNext(None)
            self.first = self.last
        else:
            self.last.setNext(Node(item))
            self.last=self.last.getNext()
    def print(self):
        t = self.first
        while t != None:
            print(t.getItem())
            t = t.getNext()
X = List()
X.add("Hello")
X.add(" World")
X.print()
