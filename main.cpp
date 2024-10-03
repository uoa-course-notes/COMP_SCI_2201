// #include <iostream>
// #include <string.h>
// #include <vector>

// enum statuses{
//   never_used,
//   tombstone,
//   occupied
// };



// class HashTable{
//   private:

//   public:
//     std::string Search(std::string key){
//       return "";
//     }

//     void Insert(std::string key){
//         if (Search(key) == ""){
//           // ensure the key does not already exist
//           // Then, take the the last character of a key as a hash value.
          
//         }

//         else{
//           // Else, we do nothing.
//           return;
//         }
//     }


//     void Delete(std::string key){
//       // Use the Search(key) as a subroutine to locate the given key's slot.
//       if (Search(key) == ""){
//         // If it's not there, do nothing.
//         return;
//       }
//       else{
//         // The key is found and we change the slot status to "tombstone".
//       }
//     }
// };



// // Utility function.
// std::string H_func(std::string value){
//   std::string hash_val = "";
//   int last_index = value.length() - 1;
//   hash_val = value[last_index];
//   return hash_val;
// }



// int main(int argc, char* argv[]){
//   // We don't need to worry about invalid inputs.
//   // Start by initializing an empty hash table
//   // HashTable* hash_table = new HashTable();

//   // std::cout << "The given inputs are: " << std::endl;
//   // Takes one line as input: n modification moves, 1 <= n <= 26
//   // for (int i=1; i<argc; i++){
//   //   // Then,
//   //   std::cout << "Input " << i << ": " << argv[i] << std::endl;
//   //   std::cout << statuses[i] << std::endl;
    
//   // }
 
  
//   // delete hash_table;


//   return 0;
// }
#include <iostream>
#include <string>
#include <vector>

enum Status { NEVER_USED, TOMBSTONE, OCCUPIED };

// HashTable class with linear probing
class HashTable {
private:
    struct Slot {
        std::string key;
        Status status;
    };
    
    std::vector<Slot> table;
    
    // Hash function using the last character of the key
    int hash(std::string key) {
        return key.back() - 'a'; // Calculate index based on last character
    }
    
public:
    HashTable() {
        // Initialize 26 slots with status NEVER_USED
        table.resize(26);
        for (int i = 0; i < 26; i++) {
            table[i].status = NEVER_USED;
        }
    }
    
    // Search function to locate a key
    int search(std::string key) {
        int index = hash(key);
        int start = index; // To avoid infinite loop, track starting point
        while (table[index].status != NEVER_USED) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return index; // Key found
            }
            index = (index + 1) % 26; // Linear probing
            if (index == start) break; // If we come back to the start, stop
        }
        return -1; // Key not found
    }
    
    // Insert function
    void insert(std::string key) {
        if (search(key) != -1) return; // Key already exists
        
        int index = hash(key);
        while (table[index].status == OCCUPIED) {
            index = (index + 1) % 26; // Linear probing
        }
        table[index].key = key;
        table[index].status = OCCUPIED;
    }
    
    // Delete function
    void remove(std::string key) {
        int index = search(key);
        if (index != -1) {
            table[index].status = TOMBSTONE;
        }
    }
    
    // Function to print the current state of the hash table
    void print() {
        for (int i = 0; i < 26; i++) {
            if (table[i].status == OCCUPIED) {
                std::cout << table[i].key << " ";
            }
        }
        std::cout << std::endl;
    }
};



int main() {
    HashTable hashTable;
    
    // Read input
    std::string input;
    getline(std::cin, input); // Get the entire input line
    
    std::string operation;
    for (size_t i = 0; i < input.length(); i += 11) {
        operation = input.substr(i, 11); // Extract the operation (e.g., Aapple, Dpear)
        char op = operation[0]; // A for insert, D for delete
        std::string key = operation.substr(1); // The key (e.g., "apple")
        
        if (op == 'A') {
            hashTable.insert(key);
        } else if (op == 'D') {
            hashTable.remove(key);
        }
    }
    
    // Print the final state of the hash table
    hashTable.print();
    
    return 0;
}
