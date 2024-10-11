class DirectAddressTable:
    # U = {0,1,2, ..., m-1} := the universe of keys where m is not too large.
    #
    #
    def __init__(self, U: list[int]) -> None:
        m = len(U)
        self.size = m 
        self.table = [None] * self.size
    
    # Insert 
    def insert(self, key, value):
        if key > self.size:
            print(f"Our DAT's size is: {self.size}. Your key is {key} > {self.size}.")
            exit()
        # Insert (key, value) pair into the direct address table
        self.table[key] = value 
    
    def delete(self, key):
        # Delete the key from the direct address table
        self.table[key] = None
    
    def search(self, key):
        if key > self.size: 
            input()
        input("Hello...")
        # Search for the key in the direct address table and return the corresponding value
        return self.table[key]
    
    def display(self):
        # Display the current state of the direct address table
        for i in range(self.size):
            if self.table[i] is not None:
                print(f"(Key {i}: Value {self.table[i]})")	








# Create a direct address table with a universe size of 10 (keys can be 0 to 9)
u_size = 10
A = [i for i in range(u_size)]
DirectAddress = DirectAddressTable(A)


# Insert key-value pairs 
DirectAddress.insert(3, "Alice")
DirectAddress.insert(2, "Bob")
DirectAddress.insert(21, "Charlie")
DirectAddress.insert(45, "AI")
DirectAddress.insert(67, "Prog")


# Display the table 
print("Initial state:")
DirectAddressTable.display()