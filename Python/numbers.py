class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


def solution(A,B):
    while A is not None or B is not None:
