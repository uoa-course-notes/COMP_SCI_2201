class Node:
    def __init__(self, data):
        self.data = data 
        self.next = None 


class Node:
    # Intializing the linked list 
    def __init__(self):
        self.head = None 


    # Insertion at the beginning 
    def insertAtBegin(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node 
    # Insertion at a specific position 
    def insertAtIndex(self, data, index):
        if index == 0:
            self.insertAtBegin(data)

        position = 0 
        current_node = self.head 
        while current_node is not None and position 

    def insertAtEnd(self, data):
        pass 
    
    def updateNode(self, val, index):
        pass 

    # Remove first node of the linked list 
    def remove_first_node(self):
        if self.head is None: return 
        self.head = self.head.next 
    # Remove last node of the linked list 
    def remove_last_node(self):
        pass 

    # Remove a node at a given index 
    def remove_at_index(self, index):
        pass 

    # Print size of the linked list 
    def sizeOfLL(self):
        pass 
    def displayList(self):
        pass 


# Creating an empty list 
list = LinkedList()
list.insertAtBegin(10)
