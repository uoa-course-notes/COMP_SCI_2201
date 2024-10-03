#include <iostream>
#include <string.h>
#include <vector>


class HashTable{
  private:

  public:
    std::string Search(std::string key){
      return "";
    }

    void Insert(std::string key){
        if (Search(key) == ""){
          // ensure the key does not already exist
          // Then, take the the last character of a key as a hash value.
          
        }

        else{
          // Else, we do nothing.
          return;
        }
    }


    void Delete(std::string key){
      // Use the Search(key) as a subroutine to locate the given key's slot.
      if (Search(key) == ""){
        // If it's not there, do nothing.
        return;
      }
      else{
        // The key is found and we change the slot status to "tombstone".
      }
    }
};



// Utility function.
std::string H_func(std::string value){
  std::string hash_val = "";
  int last_index = value.length() - 1;
  hash_val = value[last_index];
  return hash_val;
}



int main(int argc, char* argv[]){
  // We don't need to worry about invalid inputs.
  // Start by initializing an empty hash table
  HashTable* hash_table = new HashTable();

  // std::cout << "The given inputs are: " << std::endl;
  // Takes one line as input: n modification moves, 1 <= n <= 26
  for (int i=1; i<argc; i++){
    // Then,
    std::cout << "Input " << i << ": " << argv[i] << std::endl;

  }

  delete hash_table;


  return 0;
}
