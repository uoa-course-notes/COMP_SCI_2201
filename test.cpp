#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>  // For string stream (to split input)

enum Status {
    NEVER_USED,
    TOMBSTONE,
    OCCUPIED
};

struct HashEntry {
    std::string key;
    Status status;
    HashEntry() : key("1"), status(NEVER_USED) {}
};

class HashTable {
    private:
        std::vector<HashEntry> table;
        int size;

        // A simple hash function: returns index based on the last character of the string.
        // h: L --> N*
        // L := {w| w is a string over E}
        // E := {a,b,c, ... ,z}
        // N* := {0,1,2, ...}
        int hashFunction(const std::string& key) {
            char lastChar = key[key.length() - 1];
            int ascii_last = lastChar - 'a';
            int index = ascii_last;
            return index;
        }

    public:
        HashTable(int tableSize) : size(tableSize) {
            table.resize(size);
        }
        // Linear probing search with tombstone checking
        int search(const std::string& key) {
            int index = hashFunction(key);
            int originalIndex = index;

            while (table[index].status != NEVER_USED) {
                if (table[index].status == OCCUPIED && table[index].key == key) {
                    return index; // Key found
                }
                // Slot is occupied but doesn't contain the objective (the slot's status is presumable the tombstone), then we move on.
                index = (index + 1) % size;
                // if (index == originalIndex) {
                //     break; // Avoid infinite loop - full cycle.
                // }
            }
            return -1; // Key not found: certain that the objective is not in the table.
        }

        void insert(const std::string& key) {
            if (search(key) != -1) {
                return; // Key already exists
            }
            // Take last character of the key as hash value.
            int index = hashFunction(key);
            // If the corresponding table slot is occupied, try the next slot.
            while (table[index].status == OCCUPIED) {
                index = (index + 1) % size; // Linear probing
            }

            // If it is not occupied (either tombstone or never used), we can replace it with the new key
            if (table[index].status == TOMBSTONE || table[index].status == NEVER_USED) {
                table[index].key = key;
                table[index].status = OCCUPIED;
            }
        }

        void remove(const std::string& key) {
            // Locate the given key's slot.
            int index = search(key);
            // key is found, change the slot status to TOMBSTONE
            if (index != -1) {
                table[index].status = TOMBSTONE; // Mark as deleted using tombstone
            }

            // key is not in the table, do nothing.
            return;
        }

       void display() {
            std::cout << "Hash Table:" << std::endl;
            for (int i = 0; i < size; i++) {
                std::cout << "Slot " << i << ": ";
                if (table[i].status == OCCUPIED) {
                    std::cout << table[i].key << " (OCCUPIED)";
                } else if (table[i].status == NEVER_USED) {
                    std::cout << "(NEVER USED)";
                } else if (table[i].status == TOMBSTONE) {
                    std::cout << "(TOMBSTONE)";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};


int h(const std::string& key){
    char last_char = key.back();
    // std::cout << last_index << std::endl;
    int index = 0;
    int ascii_last = last_char - 'a';
    int capacity = 26;

    index =  ascii_last % capacity; // get the ascii value of the last character of key
    return index;
}


int main() {
    // Initialize an empty hash table of size 26.
    HashTable hashTable(26); // Table size 26, as there are 26 letters in the alphabet
    int v = 1;
    while (v){
        std::string inputLine;
        std::cout << "Enter: ";
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
        // std::cout.flush();
        std::cout << "Quit? 1 or -1: "; std::cin >> v;
        // Flush the remaining newline character from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (v == -1) break;
    }
    return 0;
}
