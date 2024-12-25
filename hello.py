class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next
    
class LinkedList:
    def __init__(self, array):
        self.head = None
        self.CreateLinkedList(array)
        self.PrintLinkedList()
    
    def CreateLinkedList(self, array):
        for element in array:
            if self.head is None:
                self.head = Node(element)
                temp = self.head
            else:
                temp.next = Node(element)
                temp = temp.next
    
    def PrintLinkedList(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=' ')
            temp = temp.next

LinkedList([1, 2, 3, 4, 5])

class NodeList:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

class Tree:
    def __init__(self, array):
        self.root = None
        self.idx = 0
        self.CreateTree(self.root, array)
        self.PrintTree(self.root)
    
    def CreateTree(self, node, array):
        if array[self.idx] != -1:
            node = NodeList(array[self.idx])
            self.idx += 1
        else:
            return None
        
        self.CreateTree(node.left, array)
        self.CreateTree(node.right, array)

        return node
    
    def PrintTree(self, node):
        if node is None:
            return None
        
        self.PrintTree(node.left)
        print(node.data, end=' ')
        self.PrintTree(node.right)

t = Tree([1, 2, -1, -1, 3, -1, -1])