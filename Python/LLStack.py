#Note: I am a C++ developer trying to learn Python, so my main focus is getting the code to work.
class Node:
    def __init__(self,item,next=None):
        self.item = item
        self.next = next
class Stack:
    def __init__(self):
        self.first = None
    def push(self,item):
        self.first = Node(item,self.first)
    def pop(self):
        item = self.first.item
        self.first = self.first.next
        return item
    def isEmpty(self):
        return self.first == None

#Test
X = Stack()
X.push("World")
X.push("Hello ")
print(X.pop() + X.pop())
