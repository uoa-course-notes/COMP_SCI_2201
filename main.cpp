#include <iostream>
#include <string.h>
#include <vector>




std::string H_func(std::string value){
  std::string hash_val = "";
  int last_index = value.length() - 1;
  hash_val = value[last_index];
  return hash_val;
}



int main(int argc, char* argv[]){
  std::vector<std::string> tests = {
    "apple",
    "orang",
    "pear"
  };

  for (unsigned int i=0; i<tests.size(); i++){
    std::string last_val = H_func(tests.at(i));
    std::cout << tests.at(i) << " with: " << last_val << std::endl;
  }




  return 0;
}
