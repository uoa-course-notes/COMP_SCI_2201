#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // For string stream (to split input)
#include <algorithm> // For std::find


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



enum Status {
    NEVER_USED,
    TOMBSTONE,
    OCCUPIED
};

struct HashEntry {
    std::string key;
    Status status;
    HashEntry() : key(""), status(NEVER_USED) {}
};

class HashTable {
private:
    std::vector<HashEntry> table;
    std::vector<std::string> insertionOrder; // To track insertion order
    int size;

    // A simple hash function: returns index based on the last character of the string.
    int hashFunction(const std::string& key) {
        return key[key.length() - 1] % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Linear probing search
    int search(const std::string& key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].status != NEVER_USED) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return index; // Key found
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                break; // Avoid infinite loop
            }
        }
        return -1; // Key not found
    }

    void insert(const std::string& key) {
        // If the key already exists, no need to insert
        if (search(key) != -1) {
            return;
        }

        int index = hashFunction(key);
        int tombstoneIndex = -1; // Keep track of the first tombstone encountered

        // Find the appropriate slot for the key using linear probing
        while (table[index].status == OCCUPIED) {
            index = (index + 1) % size;
        }

        // Insert into tombstone slot if available
        table[index].key = key;
        table[index].status = OCCUPIED;

        // Track the insertion order
        insertionOrder.push_back(key);
    }

    void remove(const std::string& key) {
        int index = search(key);
        if (index != -1) {
            table[index].status = TOMBSTONE; // Mark as deleted
            // Remove from insertionOrder vector
            auto it = std::find(insertionOrder.begin(), insertionOrder.end(), key);
            if (it != insertionOrder.end()) {
                insertionOrder.erase(it);
            }
        }
    }

    void display() {
        for (const auto& key : insertionOrder) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Initialize an empty hash table of size 26.
    HashTable hashTable(26); // Table size 26, as there are 26 letters in the alphabet

    std::string inputLine;
    std::getline(std::cin, inputLine); // Read entire line of input

    std::stringstream ss(inputLine);
    std::string operation;
    while (ss >> operation) {
        char action = operation[0]; // A or D
        std::string key = operation.substr(1); // Rest of the string (the key)

        if (action == 'A') {
            hashTable.insert(key);
        } else if (action == 'D') {
            hashTable.remove(key);
        }
    }

    hashTable.display();

    return 0;
}
