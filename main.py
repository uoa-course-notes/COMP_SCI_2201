class AVLNode:
    """Node class for AVL tree."""
    def __init__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None

class AVLTree:
    """Class for AVL Tree."""
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        """Insert key into the AVL tree."""
        if not root:
            return AVLNode(key)
        if key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        else:
            return root

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)

        # Left heavy
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)

        # Right heavy
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)

        # Left Right case
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        # Right Left case
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def delete(self, root, key):
        """Delete a key from the AVL tree."""
        if not root:
            return root
        if key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            temp = self.get_min_value_node(root.right)
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)

        if root is None:
            return root

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)

        # Left heavy
        if balance > 1 and self.get_balance(root.left) >= 0:
            return self.right_rotate(root)

        # Left Right case
        if balance > 1 and self.get_balance(root.left) < 0:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        # Right heavy
        if balance < -1 and self.get_balance(root.right) <= 0:
            return self.left_rotate(root)

        # Right Left case
        if balance < -1 and self.get_balance(root.right) > 0:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def left_rotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y

    def right_rotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y

    def get_min_value_node(self, node):
        if node is None or node.left is None:
            return node
        return self.get_min_value_node(node.left)

    def inorder_traversal(self, root):
        if root:
            return self.inorder_traversal(root.left) + [root.key] + self.inorder_traversal(root.right)
        return []

    def preorder_traversal(self, root):
        if root:
            return [root.key] + self.preorder_traversal(root.left) + self.preorder_traversal(root.right)
        return []

    def postorder_traversal(self, root):
        if root:
            return self.postorder_traversal(root.left) + self.postorder_traversal(root.right) + [root.key]
        return []

def process_commands(commands):
    N = len(commands)
    # print(commands[:-1])
    # input()

    # if not commands:
    #     print("EMPTY before processing.")
    #     return
    
    
    # Initializing an empty AVL tree 
    tree = AVLTree()
    root = None

    # Process all the operations
    for command in commands[:-1]:
        if command.startswith('A'):
            value = int(command[1:])
            root = tree.insert(root, value)
        elif command.startswith('D'):
            value = int(command[1:])
            root = tree.delete(root, value)

    # Last command is a traversal operation (IN, PRE, POST)
    last_command = commands[N-1]
    if last_command == 'IN':
        result = tree.inorder_traversal(root)
    elif last_command == 'PRE':
        result = tree.preorder_traversal(root)
    elif last_command == 'POST':
        result = tree.postorder_traversal(root)
    else:
        result = []

    
    if result:
        print(" ".join(map(str, result)))
    else:
        print("EMPTY")
        

# if __name__ == "__main__":
import sys
commands = sys.argv[1:]
process_commands(commands)
