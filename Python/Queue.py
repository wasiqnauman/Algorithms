#Note: I am a C++ developer trying to learn Python, so my main focus is getting the code to work.

class Node:
    def __init__(self,item,next=None):
        self.item = item
        self.next = next
        
        
class Queue:
    def __init__(self):
        self.first = None
        self.last = None
        
    def enqueue(self,item):
        if self.first is None:
            self.last = Node(item)
            self.first = self.last
        else:
            self.last.next = Node(item)
            self.last = self.last.next
            
    def dequeue(self):
        item = self.first.item
        self.first = self.first.next
        return item
    
    def isEmpty(self):
        return self.first is None

    
#Test
X = Queue()
X.enqueue("Hello ")
X.enqueue("World")
print(X.dequeue() + X.dequeue())
